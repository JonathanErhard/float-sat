/*
 * lsm9ds1.h
 *
 *  Created on: 01.12.2020
 *      Author: Michael Strohmeier
 */

#pragma once

#include "sensors/imu/imu.h"

class LSM9DS1 : public IMU, public Sensor_SPI{
	HAL_GPIO *csXG;
	HAL_GPIO *csM;
	HAL_GPIO *imuEN;

	Matrix3D_F rot;

	uint8_t rxBuf[12] = { 0 };
	uint8_t txBuf[3] = { 0 };
	int32_t error[1] = { 0 };

	bool isEye;
	float signx, signy, signz;
	float accConv, gyroConv, magConv;
	uint32_t spi_clk_rate;


public:

	LSM9DS1(HAL_SPI *spi, HAL_GPIO *csXG, HAL_GPIO *csM, uint32_t spi_clk_rate=1000000, Semaphore *sem = NULL, HAL_GPIO *imuEN = NULL);
	LSM9DS1(HAL_SPI *spi, HAL_GPIO *csXG, HAL_GPIO *csM, Matrix3D_F rot, uint32_t spi_clk_rate=1000000,  Semaphore *sem = NULL, HAL_GPIO *imuEN = NULL);
	virtual ~LSM9DS1(){};
	bool init();
	void reset();
	bool readAcc(Vector3D_F &data) __attribute__((optimize("-O3")));
	bool readGyro(Vector3D_F &data) __attribute__((optimize("-O3")));
	bool readMag(Vector3D_F &data) __attribute__((optimize("-O3")));
	bool readTemp(float &temperature);
};
