// generated using CreateApp.sh

#include "sensors.h"

#include "hal/hal_adc.h"

// Sun Sensor adc
#define solarPin RODOS::ADC_CHANNEL::ADC_CH_004
#define sunFilterSize 5
RODOS::HAL_ADC adcSolarSensor(RODOS::ADC_IDX::ADC_IDX1);

int iteration = 0;

void Sensors::initialize()
{
}

// Thread methods
void Sensors::initCollectData()
{
	// init IMU and the registers required to read i2c
	imu.init(400000);

	// init solar sensor
	adcSolarSensor.config(RODOS::ADC_PARAMETER_TYPE::ADC_PARAMETER_RESOLUTION, 12);
	adcSolarSensor.init(solarPin);
}

void Sensors::runCollectData()
{
	iteration++;
	imu.read_adj();
	imu.cpy_adj(imuTopicBuffer.accelerometer, imuTopicBuffer.gyroscope, imuTopicBuffer.magnetometer);
	imuDataTopic.publish(imuTopicBuffer);
}

// Telecommand methods
bool Sensors::handleTelecommandNOP()
{
	return false;
}

bool Sensors::handleTelecommandCalibGyro()
{
	return true;
}

float SUN_RAW_VAL = 0;
float SUN_VAL = 0;
float SUN_BOUND[2] = {0, 1};

void Sensors::readRawSunSensor()
{
	u_int16_t sum = 0;
	for (int i = 0; i < sunFilterSize; i++)
		sum += adcSolarSensor.read(solarPin);
	SUN_RAW_VAL = ((float)sum) / sunFilterSize;
}

void Sensors::readSunSensor()
{
	readRawSunSensor();
	SUN_VAL = (SUN_VAL - SUN_BOUND[0]) / (SUN_BOUND[1] - SUN_BOUND[0]);
	//  TODO publish
}