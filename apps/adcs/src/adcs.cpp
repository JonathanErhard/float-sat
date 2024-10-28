//generated using CreateApp.sh

// Author Konstantin Winkel

#include "adcs.h" 
#include "matlib.h"

#define ADCS_THREAD_TIME 10.0f //ms

#define MAX_ERROR_SUM 10000
#define ADCS_MAX_MOTOR_SPEED  2000.0f
#define ADCS_MIN_MOTOR_SPEED -2000.0f

#define MISSION_INCREMENTS 20

void Adcs::initialize(){

}


//Thread methods
void Adcs::initAdcsThread() {
	for(int i = 0; i <10;i++){
		gyroBufferYaw.put(0.0f);
		gyroBufferRoll.put(0.0f);
		gyroBufferPitch.put(0.0f);

		positionRb.put({0.0f,0.0f});
		deltaRb.put(0.0f);
	}
}
void Adcs::velocityControl(){

	control_output_pi = ((reactWSpeed-2500)*0.5f - (satellite_velocity-Adcs::desired_velocity))/0.5f;

	//outp = (reacS*I - (sv-vd))/I

	if(Adcs::control_output_pi > ADCS_MAX_MOTOR_SPEED) Adcs::control_output_pi = ADCS_MAX_MOTOR_SPEED;
	if(Adcs::control_output_pi < ADCS_MIN_MOTOR_SPEED) Adcs::control_output_pi = ADCS_MIN_MOTOR_SPEED;
	desiredMotorSpeedTopic.publish({control_output_pi+2500.0f});
}

void Adcs::runAdcsThread() {
	//RODOS::PRINTF("X mag: %f sun: %f\n", double(imu.magnetometer[0]), double(cos(Adcs::sunposition.position*M_PI/180)));
	//RODOS::PRINTF("Y mag: %f sun: %f\n", double(imu.magnetometer[1]), double(-sin(Adcs::sunposition.position*M_PI/180)));
	float pos;
	deltaRb.put(imu.gyroscope[2]*float(M_PI/180));
	float deltaSum = 0.0f;
	for(int i = 0; i < 10; i++){
		deltaSum+=deltaRb.vals[i];
	}

	if(use_mag){
		float mx = imu.magnetometer[0];
		float my = imu.magnetometer[1];
		float mz = imu.magnetometer[2];
		float r = imu.gyroscope[0]*float(M_PI/180);
		float p = imu.gyroscope[1]*float(M_PI/180);
		float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
   		float cy = my*cos(r) + mz*sin(r) ;
		positionRb.put({cx, cy});
	}
	else{
		positionRb.put({float(sin(Adcs::sunposition.position*float(M_PI/180))), float(-cos(Adcs::sunposition.position*float(M_PI/180)))});
	}
	float posAvgX = 0.0f;
	float posAvgY = 0.0f;
	for(int i = 0; i < 10; i++){
		posAvgX+=positionRb.vals[i].x;
		posAvgY+=positionRb.vals[i].y;
	}

	pos = atan2f(posAvgX,posAvgY) + (deltaSum*0.01f)/2;
	if(pos > 180) pos = -360+pos;
	else if(pos < -180) pos = 360+pos;
	

	gyroBufferYaw.put(imu.gyroscope[2]);
	gyroBufferPitch.put(imu.gyroscope[1]);
	gyroBufferRoll.put(imu.gyroscope[0]);
	float gyroSpeedSumYaw=0.0f;
	float gyroSpeedSumPitch=0.0f;
	float gyroSpeedSumRoll=0.0f;
	for(int i = 0; i < 10;i++){
		gyroSpeedSumYaw+=gyroBufferYaw.vals[i];
		gyroSpeedSumPitch+=gyroBufferPitch.vals[i];
		gyroSpeedSumRoll+=gyroBufferRoll.vals[i];
	}																																								//imu.magnetometer[0], imu.magnetometer[1],imu.magnetometer[2]												
	satellite_velocity=gyroSpeedSumYaw/10;	
																																									// sunvalues.data[3]-sunvalues.data[1], sunvalues.data[2]-sunvalues.data[0], 0												
	auto stdTM = this->standardTelemetry.access();
	stdTM->Roll = atan2f(imu.accelerometer[0], -imu.accelerometer[2])*float(180/M_PI) - 180.0f;
	stdTM->Pitch = asinf(-imu.accelerometer[1])*float(180/M_PI);
	stdTM->Yaw = pos*float(180/M_PI);
	stdTM->Speed = satellite_velocity;

	satellite_position= pos*float(180/M_PI);

	attitudeDeterminationTopic.publish({Adcs::satellite_position, Adcs::satellite_velocity});

	switch (Adcs::control_mode)
	{			
		case CONTROL_MODE_STANDBY:
			break;
		case CONTROL_MODE_PI: //Constant Speed
			Adcs::velocityControl();
			break;

		case CONTROL_MODE_PID: //Constant Position 
			{ 
				float abs_err = Adcs::desired_position - Adcs::satellite_position;
				Adcs::error_pos = fmod(abs_err+180.0f, 360.0f)-180.0f;
    			if(fabs(Adcs::error_pos) >180)  Adcs::error_pos = - (Adcs::error_pos - 180);	
				
				Adcs::error_pos*=Adcs::position_PC_values[0];
				error_inc = Adcs::error_pos;
				if(error_inc > Adcs::position_PC_values[1]) error_inc = Adcs::position_PC_values[1];
				if(error_inc < -Adcs::position_PC_values[1]) error_inc = -Adcs::position_PC_values[1];

				if(fabs(error_inc)<1.0f) {
					if(error_inc > 0)
					error_inc = error_inc * error_inc;
					else error_inc = -error_inc * error_inc;
				}

				desired_velocity = error_inc;
				control_output_position = desired_velocity;
				Adcs::velocityControl();
				break;
				
			}
			break;
		default:
			Adcs::desired_velocity = 0.0f;
			
			Adcs::control_mode = 0;
			RODOS::PRINTF("Stopping Sat\n");
			break;
	}

	//TODO convert control values to desired value for reaction wheel control :thinkink:

	Adcs::iterator++;
	if(Adcs::iterator > 10) {
		//Stability
		float speedSum = fabs(satellite_velocity)+0.2f*(fabs(gyroSpeedSumRoll/10)+fabs(gyroSpeedSumPitch/10.0f));
		if(Adcs::control_mode == CONTROL_MODE_PI && fabs(Adcs::desired_velocity - Adcs::satellite_velocity) < 2.0f){
			isStableTopic.publish({speedSum < 10.0f});
		}
		
		//Has reached Position
		else if(RODOS::NOW() - lastResetTime > 3*RODOS::SECONDS &&
			speedSum<5.0f && fabs(Adcs::desired_position - Adcs::satellite_position) < 2.0f){
			isStableTopic.publish({speedSum < 10.0f});
			//Do the things
			if(mode.mode == 9){
				if(mode.submode == 2){
					RODOS::PRINTF("Stable 0 angle reached\n");
					mode.submode = 3;
					modeTopic.publish(Adcs::mode);
				}
			}

			if(mode.mode == 7 && mode.submode == 0){
				RODOS::PRINTF("Reached the sun\n");
				mode.submode = 1;
				modeTopic.publish(Adcs::mode);
			}

			if(Adcs::mode.mode == 8) {
				if(Adcs::mode.submode == 1){
					Adcs::mode.submode = 2;
					generated::modeTopic.publish(Adcs::mode);
				}
			}
		}
		else isStableTopic.publish({false});

		//TM
		Adcs::iterator = 0;
    	Adcs::adcs_alive.timeout = RODOS::NOW() + 5*RODOS::SECONDS;
		corfuAppIsAliveTopic.publish(Adcs::adcs_alive);
		updateStdTM();
  	}
}


//Telecommand methods
bool Adcs::handleTelecommandNOP() {
	RODOS::PRINTF("ADCS -> NOP\n");
	return true;
}

bool Adcs::handleTelecommandSetAngularPosition(const generated::SetAngularPosition &setAngularPosition) {
	RODOS::PRINTF("ADCS -> SetAngularPosition { %f }\n", (double) setAngularPosition.AngularPosition);
	
	Adcs::desired_position = setAngularPosition.AngularPosition;
	Adcs::control_mode = CONTROL_MODE_PID;
	return true;
}

bool Adcs::handleTelecommandSetAngularVelocity(const generated::SetAngularVelocity &setAngularVelocity) {
	RODOS::PRINTF("ADCS -> SetAngularVelocity { %f }\n", (double) setAngularVelocity.AngularVelocity);

	Adcs::desired_velocity = setAngularVelocity.AngularVelocity;
	Adcs::control_mode = CONTROL_MODE_PI;

	return true;
}

bool Adcs::handleTelecommandSetPCControlValue(const generated::SetPCControlValue &setPIDControlValue) {
	RODOS::PRINTF("ADCS -> SetPIDControlValue { %d %f }\n", setPIDControlValue.identifier, (double)setPIDControlValue.value);

	if(setPIDControlValue.identifier > 3) return false;

	Adcs::position_PC_values[setPIDControlValue.identifier] = setPIDControlValue.value;
	handleTelecommandSendPCControlValues();
	return true;
}

bool Adcs::handleTelecommandSendPCControlValues() {
	RODOS::PRINTF("ADCS -> SendPIControlValues\n");

	corfu::Telemetry telemetry;

	pCValues_tm.P_Value = Adcs::position_PC_values[0];
	pCValues_tm.C_Value = Adcs::position_PC_values[1];

	telemetry = finalizeTelemetry(pCValues_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);

	return true;
}


bool Adcs::handleTelecommandSetADCSControlMode(const generated::SetADCSControlMode &message){
	RODOS::PRINTF("ADCS -> SetADCSControlMode\n");

	Adcs::control_mode = message.mode;
	if(message.mode == 0) {
		desiredMotorSpeedTopic.publish({2500.0f});
	}
	return true;
}

bool Adcs::handleTelecommandSwitchMagSS(const generated::SwitchMagSS &switchMagSS){
	RODOS::PRINTF("ADCS -> SwitchMagSS\n");
	lastResetTime = RODOS::NOW();
	if(switchMagSS.sensor == 0){
		use_mag = true;
	}
	else if(switchMagSS.sensor == 1){
		use_mag = false;
	}
	else{
		RODOS::PRINTF("BAD SENSOR SET\n");
	}

	return true;
}

//Topic methods
void Adcs::handleTopicBiasOffsetTopic(generated::BiasOffsetTopic &message){
	reactWSpeed = message.offset;
}

void Adcs::handleTopicImuDataTopic(generated::ImuDataTopic &message) {
	Adcs::imu = message;
}

void Adcs::handleTopicSunPositionTopic(generated::SunPositionTopic &message) {
	Adcs::sunposition = message;
}

void Adcs::handleTopicModeTopic(generated::ModeTopic &message) {
	Adcs::mode = message;
	if (Adcs::mode.mode == 9) {
		if(Adcs::mode.submode == 0){
			handleTelecommandSetAngularVelocity({20.0f});
			return;
		}
		else if(Adcs::mode.submode == 1){
			lastResetTime = RODOS::NOW();
			handleTelecommandSetAngularPosition({0.0f});
			Adcs::mode.submode = 2;
			modeTopic.publish(Adcs::mode);
			return;
		}
		else if(Adcs::mode.submode == 4){
			RODOS::PRINTF("Start sun pointing\n");
			lastResetTime = RODOS::NOW();
			handleTelecommandSetAngularPosition({Adcs::sunposition.offset});
			Adcs::mode.mode = 7;
			Adcs::mode.submode = 0;
			modeTopic.publish(Adcs::mode);
		}
	}

	if(Adcs::mode.mode == 8) {
		if(Adcs::mode.submode == 0){
			Adcs::mode.submode = 1;
			generated::modeTopic.publish(Adcs::mode);

			if(Adcs::last_mission_position == 360.0f) Adcs::last_mission_position = Adcs::satellite_position;

			Adcs::last_mission_position = float(int(Adcs::last_mission_position + MISSION_INCREMENTS) / MISSION_INCREMENTS) * MISSION_INCREMENTS;
			
			if(Adcs::last_mission_position > 180.0f) Adcs::last_mission_position -= 360.0f;
			handleTelecommandSetAngularPosition({Adcs::last_mission_position});
		}
	}
}

void Adcs::handleTopicDesiredStateValueTopic(generated::DesiredStateValueTopic &message) {
	switch (Adcs::control_mode)
	{
		case CONTROL_MODE_PI:
			Adcs::desired_velocity = message.value;
			break;
		case CONTROL_MODE_PID:
			Adcs::desired_position = message.value;
			break;
		default:
			break;
	}
}

//own methods

void Adcs::updateStdTM(){
	auto stdTM = this->standardTelemetry.access();
	stdTM->TargetAngularPosition = Adcs::desired_position;
	stdTM->TargetAngularVelocity = Adcs::desired_velocity;
	stdTM->PIDcontrolOutput = Adcs::control_output_position;
	stdTM->PIcontrolOutput = Adcs::control_output_pi;
	stdTM->PositionError = Adcs::error_pos;
}
