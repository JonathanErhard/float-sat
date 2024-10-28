//generated using CreateApp.sh

#include <reaction-wheel-control-generated/reaction-wheel-control.h> 

#include "ringbuffer.h"

#include "math.h"
#include "stdint.h"
#include "stm32f4xx_conf.h"

class ReactionWheelControl: public generated::ReactionWheelControl{

	public:

	void initialize() override;

	//Thread methods
	void initReactionWheelControlThread() override;
	void runReactionWheelControlThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandSetPIControlValueWheel(const generated::SetPIControlValueWheel &setPIControlValue) override;
	bool handleTelecommandSendPIControlValues() override;
	bool handleTelecommandSetDesiredSpeed(const generated::SetDesiredSpeed &setDesiredSpeed) override;

	//Topic methods
	void handleTopicDesiredMotorSpeedTopic(generated::DesiredMotorSpeedTopic &message) override;

	//own methods
	void MotorSpeedUpdate();
	void EncoderInit();


	protected:
		float rotation_speed = 0.0f;
		float PI_values[2] = { 5.0f , 15.0f}; // 0 = P-value, 1 = I-value

		float desired_speed = 2500.0f;
		float control_output = 0.0;
		float prev_control_output = 0.0;
		float error = 0.0f; // current error for P
		float prev_error = 0.0f;
		float error_sum = 0.0f; //for I component
		float values[10];
		RODOS::RingBuffer<float, 10> reader_buffer;
		uint16_t medianRejections = 0;

		float current_pwm = 0.0f;
		float prev_pwm = 0.0f;
		int32_t current_int_pwm = 0;
		float offset = 0.0f;

		int iterator = 0; // for alive
		corfu::Alive reactioncontrol_alive;	
		generated::AttitudeDeterminationTopic atd;
		void handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) override;

		void updateStdTM();
};
