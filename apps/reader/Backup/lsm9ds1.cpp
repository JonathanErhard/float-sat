/*
 * LSM9DS1.cpp
 *
 *  Created on: 27.01.2017
 *      Author: Michael Strohmeier
 */

#include "lsm9ds1.h"
#include "lsm9ds1_def.h"

#include "rodos.h"
#include "math.h"

#include "misc/macros.h"

#define READ							0x80
#define MULTIPLE_READ					0x40

LSM9DS1::LSM9DS1(HAL_SPI *spi, HAL_GPIO *csXG, HAL_GPIO *csM, uint32_t spi_clk_rate, Semaphore *sem, HAL_GPIO *imuEN) :
	IMU("LSM9DS1"), Sensor_SPI(spi, sem){
	this->rot = Matrix3D_F(Vector3D_F(1,0,0),Vector3D_F(0,1,0),Vector3D_F(0,0,1));
	this->csM = csM;
	this->csXG = csXG;
	this->imuEN = imuEN;
	this->isEye = true;
	this->signx = 1;
	this->signy = 1;
	this->signz = 1;
	this->accConv = LSM9DS1_ACCEL_MG_LSB_4G / 1000.f;
	this->gyroConv = deg2radf(LSM9DS1_GYRO_DPS_DIGIT_500DPS);
	this->magConv = LSM9DS1_MAG_MGAUSS_4GAUSS / 1000.f;
	this->spi_clk_rate = spi_clk_rate;
}

LSM9DS1::LSM9DS1(HAL_SPI *spi, HAL_GPIO *csXG, HAL_GPIO *csM,
		        Matrix3D_F rot, uint32_t spi_clk_rate, Semaphore *sem, HAL_GPIO *imuEN):
		IMU("LSM9DS1"), Sensor_SPI(spi, sem) {
	this->rot = rot;
	this->csM = csM;
	this->csXG = csXG;
	this->imuEN = imuEN;
	if(fabs(rot.r[0][0]) == 1 && fabs(rot.r[1][1]) == 1 && fabs(rot.r[2][2]) == 1){
		this->isEye = true;
		this->signx = rot.r[0][0];
		this->signy = rot.r[1][1];
		this->signz = rot.r[2][2];
	} else {
		this->isEye = false;
		this->signx = 1;
		this->signy = 1;
		this->signz = 1;
	}
	this->accConv = LSM9DS1_ACCEL_MG_LSB_4G / 1000.f;
	this->gyroConv = deg2radf(LSM9DS1_GYRO_DPS_DIGIT_500DPS);
	this->magConv = LSM9DS1_MAG_MGAUSS_4GAUSS / 1000.f;
	this->spi_clk_rate = spi_clk_rate;
}

bool LSM9DS1::init(){

	spi->reset();
	spi->init(spi_clk_rate);
	csXG->init(true, 1, 1);
	csM->init(true, 1, 1);
	if (imuEN != NULL)
		imuEN->init(true, 1, 1);

	if (imuEN != NULL){
		imuEN->init(true, 1, 0);
		if(RODOS::isSchedulerRunning()){
			Thread::suspendCallerUntil(NOW()+200 * MILLISECONDS);
		} else {
			BUSY_WAITING_UNTIL(NOW()+200 * MILLISECONDS);
		}
		imuEN->setPins(1);
	}

	int xg_id, m_id;
	txBuf[0] = LSM9DS1_WHO_AM_I_XG | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 1);
	xg_id = rxBuf[0];

	txBuf[0] = LSM9DS1_WHO_AM_I_M | READ;
	error[0] += WRITEREAD_HD(csM, txBuf, 1, rxBuf, 1);
	m_id = rxBuf[0];

	// Enable Gyroscope
	txBuf[0] = LSM9DS1_CTRL_REG1_G;
	// 238 Hz, 500 DPS, 14 Hz BW
//	txBuf[1] = LSM9DS1_G_ODR_952HZ | LSM9DS1_G_FS_2000 | LSM9DS1_G_LPF2_HIGH;
	// 952 Hz, 500 DPS, 33 Hz BW
	txBuf[1] = LSM9DS1_G_ODR_476HZ | LSM9DS1_G_FS_500 | LSM9DS1_G_LPF2_LOW;
	error[0] += WRITE(csXG, txBuf, 2);

	// Enable Accelerometer
	txBuf[0] = LSM9DS1_CTRL_REG6_XL;
	// 238 Hz, +/- 2G, 50 Hz BW
	txBuf[1] = LSM9DS1_X_ODR_476HZ | LSM9DS1_X_FS_4G | LSM9DS1_X_BW_50HZ;
	// 952 Hz, +/- 4G, 50 Hz BW
//	txBuf[1] = LSM9DS1_X_ODR_952HZ | LSM9DS1_X_FS_4G | LSM9DS1_X_BW_50HZ;
	error[0] += WRITE(csXG, txBuf, 2);

	// Enable Acc/Gyro data ready interrupt
	txBuf[0] = LSM9DS1_INT1_CTRL;
	txBuf[1] = LSM9DS1_INT1_IG_XL | LSM9DS1_INT1_DRDY_XL;
	error[0] += WRITE(csXG, txBuf, 2);

	// Enable Temperature data ready interrupt
	txBuf[0] = LSM9DS1_INT2_CTRL;
	txBuf[1] = LSM9DS1_INT2_DRDY_XL;
	error[0] += WRITE(csXG, txBuf, 2);

	// Enable Magnetometer
	txBuf[0] = LSM9DS1_CTRL_REG1_M;
	txBuf[1] = LSM9DS1_M_TEMP_COMP | LSM9DS1_M_OM_XY_ULTRA | LSM9DS1_M_ODR_80 | LSM9DS1_M_FAST_ODR;
	error[0] += WRITE(csM, txBuf, 2);

	txBuf[0] = LSM9DS1_CTRL_REG2_M;
	txBuf[1] = LSM9DS1_M_FS_4;
	error[0] += WRITE(csM, txBuf, 2);

	txBuf[0] = LSM9DS1_CTRL_REG3_M;
	txBuf[1] = LSM9DS1_M_I2C_DISABLE | LSM9DS1_M_SPI_ENABLE | LSM9DS1_M_MD_CONT;
	error[0] += WRITE(csM, txBuf, 2);

	txBuf[0] = LSM9DS1_CTRL_REG4_M;
	txBuf[1] = LSM9DS1_M_OM_Z_ULTRA;
	error[0] += WRITE(csM, txBuf, 2);

	if (xg_id != LSM9DS1_XG_ID || m_id != LSM9DS1_M_ID) {
		PRINTF("LSM9DS1 ERROR %ld 0x%x 0x%x\n", error[0], xg_id, m_id);
		return false;
	} else {
		return true;
	}
}

void LSM9DS1::reset(){
	if (imuEN != NULL){
		imuEN->setPins(0);
		delay(50 * MICROSECONDS);
	}
	spi->reset();
	if (imuEN != NULL)
		imuEN->setPins(1);
	spi->init();
}

bool LSM9DS1::readAcc(RODOS::Vector3D_F &data) {
	txBuf[0] = LSM9DS1_OUT_X_L_XL | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 6);

	data.x = static_cast<int16_t>(rxBuf[1] << 8 | rxBuf[0]) * accConv;
	data.y = static_cast<int16_t>(rxBuf[3] << 8 | rxBuf[2]) * accConv;;
	data.z = static_cast<int16_t>(rxBuf[5] << 8 | rxBuf[4]) * accConv;;

	if(!isEye){
		data = rot * data;
	} else {
		data.x *= signx;
		data.y *= signy;
		data.z *= signz;
	}

	return (error[0] == 7);
}

bool LSM9DS1::readGyro(RODOS::Vector3D_F &data) {
	txBuf[0] = LSM9DS1_OUT_X_L_G | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 6);

	data.x = static_cast<int16_t>(rxBuf[1] << 8 | rxBuf[0]) * gyroConv;
	data.y = static_cast<int16_t>(rxBuf[3] << 8 | rxBuf[2]) * gyroConv;
	data.z = static_cast<int16_t>(rxBuf[5] << 8 | rxBuf[4]) * gyroConv;

	if(!isEye){
		data = rot * data;
	} else {
		data.x *= signx;
		data.y *= signy;
		data.z *= signz;
	}

	return (error[0] == 7);
}

bool LSM9DS1::readMag(RODOS::Vector3D_F &data) {
	txBuf[0] = LSM9DS1_OUT_X_L_M | READ | MULTIPLE_READ;
	error[0] = WRITEREAD_HD(csM, txBuf, 1, rxBuf, 6);

	data.x = -((float) static_cast<int16_t>(rxBuf[1] << 8 | rxBuf[0]))* magConv;
	data.y =  ((float) static_cast<int16_t>(rxBuf[3] << 8 | rxBuf[2])) * magConv;
	data.z =  ((float) static_cast<int16_t>(rxBuf[5] << 8 | rxBuf[4])) * magConv;

	if(!isEye){
		data = rot * data;
	} else {
		data.x *= signx;
		data.y *= signy;
		data.z *= signz;
	}

	return (error[0] == 7);
}

bool LSM9DS1::readTemp(float &temperature) {
	txBuf[0] = LSM9DS1_OUT_TEMP_L | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 2);

	int tmp = (int) ((rxBuf[1] << 8) | rxBuf[0]);
	// Convert from 12 bit to 16 bit
	if (tmp & 0x0800)
		tmp |= 0xF000;

	temperature = ((float) tmp / LSM9DS1_TEMP_LSB_PER_C) + LSM9DS1_TEMP_OFFSET;

	return (error[0] == 3);
}











