// generated using CreateApp.sh

#include <power-generated/power.h>

class Power : public generated::Power
{
	generated::PowerTopic powerTopicBuffer;

public:
	void
	initialize() override;

	// Thread methods
	void initMainthread() override;
	void runMainthread() override;

	// Telecommand methods
	bool handleTelecommandNOP() override;

	// read methods
	void readVoltage();
	void readCurrent();
	void update_led();

	void updateStdTM();
};
