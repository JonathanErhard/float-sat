// generated using CreateApp.sh

#include "sensors.h"
#include "hal/hal_i2c.h"

#pragma region imu
RODOS::HAL_I2C imu(RODOS::I2C_IDX::I2C_IDX2); // PB10 & PB11

#define AccADDR 0x6B // also includes gyro
#define MagADDR 0x1E

// Buffers for data to be read into
uint8_t DATA_L[1] = {0};
uint8_t DATA_H[1] = {0};

/*
 *  Buffers for all processed values
 */

// GYRO
float GYR_CALIB_VALS[3] = {1.26502215f, -0.03441086f, 0.77206468f}; // fill through external programm!
float GYR_REAL_VALS[3] = {0.0f, 0.0f, 0.0f};
int16_t GYR_RAW_VALS[3] = {0, 0, 0};

// ACCELEROMETER
float ACC_CALIB_VALS[3] = {-0.10875375f, -0.01491124f, 0.03084271f}; // fill through external programm!
float ACC_REAL_VALS[3] = {0.0f, 0.0f, 0.0f};
int16_t ACC_RAW_VALS[3] = {0, 0, 0};

// MAGNETOMETER
float MAG_REAL_VALS[3] = {0.0f, 0.0f, 0.0f};
int16_t MAG_RAW_VALS[3] = {0, 0, 0};

/*
 *  REGISTER ADDRESSES
 */

// GYRO
uint8_t GYR_X_L[1] = {0x18};
uint8_t GYR_X_H[1] = {0x19};
uint8_t GYR_Y_L[1] = {0x1A};
uint8_t GYR_Y_H[1] = {0x1B};
uint8_t GYR_Z_L[1] = {0x1C};
uint8_t GYR_Z_H[1] = {0x1D};

// ACCELLEROMETER
uint8_t ACC_X_L[1] = {0x28};
uint8_t ACC_X_H[1] = {0x29};
uint8_t ACC_Y_L[1] = {0x2A};
uint8_t ACC_Y_H[1] = {0x2B};
uint8_t ACC_Z_L[1] = {0x2C};
uint8_t ACC_Z_H[1] = {0x2D};

// MAGNETOMETER
uint8_t MAG_X_L[1] = {0x28};
uint8_t MAG_X_H[1] = {0x29};
uint8_t MAG_Y_L[1] = {0x2A};
uint8_t MAG_Y_H[1] = {0x2B};
uint8_t MAG_Z_L[1] = {0x2C};
uint8_t MAG_Z_H[1] = {0x2D};

struct magCalib
{
	float xMin, yMin, zMin, xMax, yMax, zMax;
} calibDataMagn;
#pragma endregion

void Sensors::initialize()
{
}

// Thread methods
void Sensors::initCollectData()
{
	imu.init(400000);
	uint8_t INIT_REG_GYR[2] = {0x10, 0b10011000};
	uint8_t INIT_REG_ACC[2] = {0x20, 0b10000011};
	uint8_t INIT_REG_MAG_1[2] = {0x20, 0b00011100};
	uint8_t INIT_REG_MAG_2[2] = {0x21, 0b01100000};
	uint8_t INIT_REG_MAG_3[2] = {0x22, 0b00000000};

	imu.write(AccADDR, INIT_REG_GYR, 2);
	imu.write(AccADDR, INIT_REG_ACC, 2);
	imu.write(MagADDR, INIT_REG_MAG_1, 2);
	imu.write(MagADDR, INIT_REG_MAG_2, 2);
	imu.write(MagADDR, INIT_REG_MAG_3, 2);
}

void Sensors::runCollectData()
{
	readIMU();
}

// Telecommand methods
bool Sensors::handleTelecommandNOP()
{
	return false;
}

bool Sensors::readIMU()
{
	/* #region ACC */
	imu.writeRead(AccADDR, ACC_X_L, 1, DATA_L, 1);
	imu.writeRead(AccADDR, ACC_X_H, 1, DATA_H, 1);
	ACC_RAW_VALS[0] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	imu.writeRead(AccADDR, ACC_Y_L, 1, DATA_L, 1);
	imu.writeRead(AccADDR, ACC_Y_H, 1, DATA_H, 1);
	ACC_RAW_VALS[1] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	imu.writeRead(AccADDR, ACC_Z_L, 1, DATA_L, 1);
	imu.writeRead(AccADDR, ACC_Z_H, 1, DATA_H, 1);
	ACC_RAW_VALS[2] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	for (int j = 0; j < 3; j++)
	{
		ACC_REAL_VALS[j] = (0.061f / 1000) * ACC_RAW_VALS[j] - ACC_CALIB_VALS[j];
	}
	/* #endregion */

	/* #region GYRO */
	imu.writeRead(AccADDR, GYR_X_L, 1, DATA_L, 1);
	imu.writeRead(AccADDR, GYR_X_H, 1, DATA_H, 1);
	GYR_RAW_VALS[0] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	imu.writeRead(AccADDR, GYR_Y_L, 1, DATA_L, 1);
	imu.writeRead(AccADDR, GYR_Y_H, 1, DATA_H, 1);
	GYR_RAW_VALS[1] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	imu.writeRead(AccADDR, GYR_Z_L, 1, DATA_L, 1);
	imu.writeRead(AccADDR, GYR_Z_H, 1, DATA_H, 1);
	GYR_RAW_VALS[2] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	for (int j = 0; j < 3; j++)
	{
		GYR_REAL_VALS[j] = (70.0f / 1000) * GYR_RAW_VALS[j] - GYR_CALIB_VALS[j];
	}
	/* #endregion */

	/* #region MAGNO */
	imu.writeRead(MagADDR, MAG_X_L, 1, DATA_L, 1);
	imu.writeRead(MagADDR, MAG_X_H, 1, DATA_H, 1);
	MAG_RAW_VALS[0] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	imu.writeRead(MagADDR, MAG_Y_L, 1, DATA_L, 1);
	imu.writeRead(MagADDR, MAG_Y_H, 1, DATA_H, 1);
	MAG_RAW_VALS[1] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	imu.writeRead(MagADDR, MAG_Z_L, 1, DATA_L, 1);
	imu.writeRead(MagADDR, MAG_Z_H, 1, DATA_H, 1);
	MAG_RAW_VALS[2] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	if (true) // is_calibratingMagn)
	{
		for (int j = 0; j < 3; j++)
		{
			MAG_REAL_VALS[j] = MAG_RAW_VALS[j];
		}
	}
	else
	{
		MAG_REAL_VALS[0] = ((MAG_RAW_VALS[0] - calibDataMagn.xMin) / (calibDataMagn.xMax - calibDataMagn.xMin)) * 2 - 1;
		MAG_REAL_VALS[1] = ((MAG_RAW_VALS[1] - calibDataMagn.yMin) / (calibDataMagn.yMax - calibDataMagn.yMin)) * 2 - 1;
		MAG_REAL_VALS[2] = ((MAG_RAW_VALS[2] - calibDataMagn.zMin) / (calibDataMagn.zMax - calibDataMagn.zMin)) * 2 - 1;
	}

	imuTopicBuffer = {
		ACC_REAL_VALS[0], ACC_REAL_VALS[1], ACC_REAL_VALS[2],
		GYR_REAL_VALS[0], GYR_REAL_VALS[1], GYR_REAL_VALS[2],
		MAG_REAL_VALS[0], MAG_REAL_VALS[1], MAG_REAL_VALS[2]};
	imuDataTopic.publish(imuTopicBuffer);

	/* #endregion */
}