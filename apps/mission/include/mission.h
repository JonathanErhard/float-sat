//generated using CreateApp.sh

#include <mission-generated/mission.h> 

class Mission: public generated::Mission{
	private:
		long time;
		int rotationspeed = 10;
		int64_t time_start;
		float attitude_start =0;

	public:

	void initialize() override;

	//Thread methods
	void initMissionThread() override;
	void runMissionThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandChangeMode(const generated::ChangeMode &changeMode) override;
	bool handleTelecommandChangeAngle(const generated::ChangeAngle &changeAngle) override;
    bool handleTelecommandSetSunConstants(const generated::SetSunConstants& setSunConstants) override;
	bool handleTelecommandSetRotationSpeed(const generated::SetRotationSpeed& rotationspeed2) override;
	

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


	float sunPosition;
	float asteroidPosition;

	//controling the motor
	uint32_t sun_height = 200; // sun height relative to sphere center [mm]
	uint32_t sun_dist = 1500;  // sun dist relative to sphere center [mm]
	int calculateMirrorAngle();
	void changeMirrorAngle(int angle);
	int currentAngle;


	//updating the stdTM
	void updateStdTM();


	//Yousefs  variables
	float speed = 0.0;
	float final_attitude_reaction = 0.0;
	float final_attitude_servo = 0.0;
	float brightest = 0.0; //measure of the brightness
	float nearest = 9999999.0; //measure of the nearest object
	bool rotationDone = 0;
	float Att_light=999; // needs to be declared to the correct declaration in RODOS 
	float Att_obj=999;
	bool isInMission;


	void rotate();
	float targetReaction(float x, float y);
	float mod(float in);

	


};
