//generated using CreateApp.sh

#include "reader.h" 
#include "rodos.h"


#define M_ADDR 0x1E
#define AG_ADDR 0x6B
HAL_I2C IMU(I2C_IDX2);
uint8_t WHO[1] ={0x0F};
       uint8_t DATA[1];

#define LSM9DS1_OUT_X_L_XL			0x28
#define LSM9DS1_OUT_X_L_G			0x18
#define LSM9DS1_OUT_X_L_M			0x28
#define LSM9DS1_OUT_TEMP_L			0x15
#define LSM9DS1_TEMP_LSB_PER_C		16
#define LSM9DS1_TEMP_OFFSET			25
#define READ						0x80
#define MULTIPLE_READ				0x40


void Reader::initialize(){
    IMU.init(400000);
    isEye=true;
    rot = Matrix3D_F(Vector3D_F(1,0,0),Vector3D_F(0,1,0),Vector3D_F(0,0,1));
	accConv = LSM9DS1_ACCEL_MG_LSB_4G / 1000.f;
	gyroConv = deg2radf(LSM9DS1_GYRO_DPS_DIGIT_500DPS);
	magConv = LSM9DS1_MAG_MGAUSS_4GAUSS / 1000.f;
}


//Thread methods
void Reader::initReadthreat() {

}

void Reader::runReadthreat() {
    RODOS::Vector3D_F accdata;
    RODOS::Vector3D_F magdata;
    RODOS::Vector3D_F gyrodata;
    float temperature;

    if(readAcc(accdata) && readGyro(magdata) && readMag(gyrodata) && readTemp(tempdata)){
		generated::imuTopic.publish(accdata,magdata,gyrodata,temperature);
	}
	hallo
        ;//generated::imuTopic.publish();
    /*if()   
        ;//publish
    if(readMag(gyrodata))
        ;//publish
    if(readTemp(tempdata))
        ;//publish*/

}


//Telecommand methods
bool Reader::handleTelecommandNOP() {
    RODOS::PRINTF("RDR:RDR_NOP\n");
	return false;
}

bool readAcc(RODOS::Vector3D_F &data) {
	txBuf[0] = LSM9DS1_OUT_X_L_XL | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 6);
    //error[0]=7;

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

bool readGyro(RODOS::Vector3D_F &data) {
	txBuf[0] = LSM9DS1_OUT_X_L_G | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 6);
    //error[0]=7;

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

bool readMag(RODOS::Vector3D_F &data) {
	txBuf[0] = LSM9DS1_OUT_X_L_M | READ | MULTIPLE_READ;
	error[0] = WRITEREAD_HD(csM, txBuf, 1, rxBuf, 6);
    //error[0]=7;

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

bool readTemp(float &temperature) {
	txBuf[0] = LSM9DS1_OUT_TEMP_L | READ;
	error[0] = WRITEREAD_HD(csXG, txBuf, 1, rxBuf, 2);
    //error[0]=3;

	int tmp = (int) ((rxBuf[1] << 8) | rxBuf[0]);
	// Convert from 12 bit to 16 bit
	if (tmp & 0x0800)
		tmp |= 0xF000;

	temperature = ((float) tmp / LSM9DS1_TEMP_LSB_PER_C) + LSM9DS1_TEMP_OFFSET;

	return (error[0] == 3);
}


