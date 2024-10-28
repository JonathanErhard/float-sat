//generated using CreateApp.sh

// Author: Konstantin Winkel

#include <adcs-generated/adcs.h> 
#include "ringbuffer.h"

#define CONTROL_MODE_STANDBY 0
#define CONTROL_MODE_PI 1
#define CONTROL_MODE_PID 2

struct XY{
	float x,y;
};

class Adcs: public generated::Adcs{

	public:

	void initialize() override;

	//Thread methods
	void initAdcsThread() override;
	void runAdcsThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandSetAngularPosition(const generated::SetAngularPosition &setAngularPosition) override;
	bool handleTelecommandSetAngularVelocity(const generated::SetAngularVelocity &setAngularVelocity) override;
	bool handleTelecommandSetPCControlValue(const generated::SetPCControlValue &setPIDControlValue) override;
	bool handleTelecommandSendPCControlValues() override;
	bool handleTelecommandSetADCSControlMode(const generated::SetADCSControlMode &setADCSControlMode) override;
	bool handleTelecommandSwitchMagSS(const generated::SwitchMagSS &switchMagSS) override;

	//Topic methods
	void handleTopicImuDataTopic(generated::ImuDataTopic &message)override;
	void handleTopicSunPositionTopic(generated::SunPositionTopic &message) override;
	void handleTopicModeTopic(generated::ModeTopic &message)override;
	void handleTopicDesiredStateValueTopic(generated::DesiredStateValueTopic &message)override;
	void handleTopicBiasOffsetTopic(generated::BiasOffsetTopic &message) override;

	//own methods
	void updateStdTM();
	void velocityControl();

	protected:
		bool use_mag = true;

		// PI and PID values
		float position_PC_values[4] = {0.2f, 8.0f}; // 0 = P-value, 1 = I-value, 2 = D-value, 3 = C-Value

		uint8_t control_mode = 0; //0 = none, 1 = PI, 2 = PID

		float reactWSpeed = 0.0f;

		RODOS::RingBuffer<XY, 10> positionRb;
		RODOS::RingBuffer<float, 10> deltaRb;

		//for velocity aka PI controller
		float desired_velocity = 0.0f;
		float control_output_pi = 0.0f;

		//for position aka PID controller
		float error_pos = 0.0f;
		float desired_position = 0.0f;
		float control_output_position = 0.0f;
		float error_sum_position = 0.0f;
		float error_inc;

		//for state estimation
		float satellite_position = 0.0f;
		RODOS::RingBuffer<float, 10> gyroBufferYaw;
		RODOS::RingBuffer<float, 10> gyroBufferRoll;
		RODOS::RingBuffer<float, 10> gyroBufferPitch;
		float satellite_velocity = 0.0f;

		//for mission
		float last_mission_position = 360.0f;
		
		int64_t lastResetTime = 0;

		//for alive signal
		int iterator = 0;
		corfu::Alive adcs_alive;

		//structs for topics -> incomming
		generated::ImuDataTopic imu;

		//structs for topics -> outgoing
		generated::SunPositionTopic sunposition;

		//structs for topics -> incomming and outgoing
		generated::ModeTopic mode;
};
