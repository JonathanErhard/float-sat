//generated using CreateApp.sh

#include <mission-generated/mission.h> 

class Mission: public generated::Mission{

	public:

	void initialize() override;

	//Thread methods
	void initMissionThread() override;
	void runMissionThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandChangeMode(const generated::ChangeMode &changeMode) override;
	bool handleTelecommandChangeAngle(const generated::ChangeAngle &changeAngle) override;

	//Topic methods
	void handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) override;
	void handleTopicProximityTopic(generated::ProximityTopic &message) override;
	void handleTopicLightSensorTopic(generated::LightSensorTopic &message) override;
	void handleTopicMissionModeTopic(generated::MissionModeTopic &message) override; //realized i dont need this

	generated::AttitudeDeterminationTopic attitude;
	generated::ProximityTopic proximity;
	generated::LightSensorTopic light;
	generated::MissionModeTopic missionMode;

	generated::ChangeMode missionModes;
	generated::ChangeAngle changeAngle;

	bool isInMission;
	float sunPosition;
	float asteroidPosition;

	//controling the motor
	void changeMirrorAngle(int angle);
	int currentAngle;

	//updating the stdTM
	void updateStdTM();
};
