// generated using CreateApp.sh

#include <control-master-generated/control-master.h>

class ControlMaster : public generated::ControlMaster
{

public:
	void initialize() override;

	// Thread methods
	void initServoThread() override;
	void runServoThread() override;

	// Topics
	void handleTopicLightSensorTopic(generated::LightSensorTopic &message) override;

	// Telecommand methods
	bool handleTelecommandNOP() override;
};
