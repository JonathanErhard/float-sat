// generated using CreateApp.sh

#include <sensors-generated/sensors.h>
#include <lsm9ds1.h>

class Sensors : public generated::Sensors
{

	IMU::LMS9DS1 imu;

public:
	// float latestIMUData[9];
	generated::ImuDataTopic imuTopicBuffer;

	void
	initialize() override;

	// Thread methods
	void initCollectData() override;
	void runCollectData() override;

	// Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandCalibGyro() override;

	// read sensor data
	void readRawSunSensor();
	void readSunSensor();
};
