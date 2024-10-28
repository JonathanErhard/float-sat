//generated using CreateApp.sh

#include <solar-array-control-generated/solar-array-control.h> 

class SolarArrayControl: public generated::SolarArrayControl{

	public:

	void initialize() override;

	//Thread methods
	void initSolarArrayLerpThread() override;
	void runSolarArrayLerpThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandSetServoAngle(const generated::SetServoAngle &setServoAngle) override;
	bool handleTelecommandUnsetManualOverride() override;
	bool handleTelecommandStableNeeded(const generated::StableNeeded &stableNeeded) override;

	//Topic methods
	void handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) override;
	void handleTopicSunPositionTopic(generated::SunPositionTopic &message) override;
	void handleTopicModeTopic(generated::ModeTopic &message) override;
	void handleTopicIsStableTopic(generated::IsStableTopic &message) override;
	void handleTopicSolarCellForbiddenTopic(generated::SolarCellForbiddenTopic &message) override;

	protected:
		float current_angle = 90.0f; //TODO setInitial Conditions when motors are here
		float desired_angle = 0.0f;
		float speed = 5; //degrees per second
		bool manual_override = false;
		bool in_sun_pointing_mode = false;
		bool rpi_forbids = false;

		bool may_run = false;

		uint8_t status = 0; // 0 = retracted, 1 = extended-fixed, 2 = extended-moving

		//structs for topics -> send
		corfu::Alive solar_array_control_alive;
		generated::SunPositionTopic sun_position;

		//structs for topics -> receive
		generated::ModeTopic current_sat_mode;
		bool isStable = false;
		bool mustBeStable = true;

		//methods
		long unsigned int angle_to_pwm(float angle);
		void updateStdTM();

};
