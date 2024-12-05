// generated using CreateApp.sh

#include <sensors-generated/sensors.h>

class Sensors : public generated::Sensors
{

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

	// read sensor data
	bool readIMU();
};
