// generated using CreateApp.sh

#include <sensors-generated/sensors.h>
#include <lsm9ds1.h>
// LIDAR

#include <math.h>
#define R2D 57.2957795131

// Winkel and my version of the driver
// #include <platform.h>
// #include <VL53L4CD_api.h>
// #include <VL53L4CD_calibration.h> // technically not needed since min doesn't change with calibration

class Sensors : public generated::Sensors
{

	IMU::LMS9DS1 imu;

	// topic buffers
	generated::ImuDataTopic imuTopicBuffer;
	generated::LightSensorTopic lightSensorBuffer;
	generated::ProximityTopic proximityBuffer;
private:
	long time;
public:
	Sensors();

	void initialize() override;

	// Thread methods
	void initCollectData() override;
	void runCollectData() override;

	// Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandCalibGyro() override;

	// read sensor data
	void readSunSensor();
	void readLIDAR();

	void publishTM();
};
