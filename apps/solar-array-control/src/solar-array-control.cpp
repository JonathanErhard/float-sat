//generated using CreateApp.sh

// Author: Konstantin Winkel

#include "solar-array-control.h" 

#include "rodos.h"
#include "hal_pwm.h"

#include <math.h>

#define PWM_FREQ 200
#define PWM_INCREMENTS 5000

#define ANGLE_DIFF_THRESHHOLD 1
#define LERP_THREAD_SLEEP 100

#define ADCS_MOVING_THRESHHOLD 0.5f

#define SUN_SENSOR_ANGLE 30.0

HAL_PWM array_1_pwm(RODOS::PWM_IDX::PWM_IDX00);
HAL_PWM array_2_pwm(RODOS::PWM_IDX::PWM_IDX01);

void SolarArrayControl::initialize(){

}


//Thread methods
void SolarArrayControl::initSolarArrayLerpThread() {
	array_1_pwm.init(PWM_FREQ, PWM_INCREMENTS);
	array_2_pwm.init(PWM_FREQ, PWM_INCREMENTS);

	//set initial values for solar array servos
	array_1_pwm.write(SolarArrayControl::angle_to_pwm(SolarArrayControl::current_angle));
	array_2_pwm.write(SolarArrayControl::angle_to_pwm(SolarArrayControl::current_angle - 5)); //offset correction
}

void SolarArrayControl::runSolarArrayLerpThread() {
	if(SolarArrayControl::status == 0) return;
	if(SolarArrayControl::may_run == false) return;
	if(SolarArrayControl::rpi_forbids == true) return;

	float angle_diff = 0.0f;
	SolarArrayControl::status = 2;

	angle_diff = SolarArrayControl::desired_angle - SolarArrayControl::current_angle;

	if(fabs(angle_diff) <= ANGLE_DIFF_THRESHHOLD){
		RODOS::PRINTF("Reached Solar panel pos\n");	
		SolarArrayControl::current_angle = SolarArrayControl::desired_angle;
		SolarArrayControl::status = 1;
	}
	else{
		SolarArrayControl::current_angle += (fabs(angle_diff)/angle_diff) * SolarArrayControl::speed * (LERP_THREAD_SLEEP / 1000.0f);
	}

	array_1_pwm.write(SolarArrayControl::angle_to_pwm(SolarArrayControl::current_angle));
	array_2_pwm.write(SolarArrayControl::angle_to_pwm(SolarArrayControl::current_angle - 5)); // offset correction

	SolarArrayControl::updateStdTM();

	//if(break_after) break;

	//if(SolarArrayControl::current_sat_mode.mode == 3 && SolarArrayControl::current_sat_mode.submode == 1){
	//	SolarArrayControl::current_sat_mode.submode = 2;
	//	generated::modeTopic.publish(SolarArrayControl::current_sat_mode);
	//}
}


//Telecommand methods
bool SolarArrayControl::handleTelecommandNOP() {
	RODOS::PRINTF("SOLAR-CONTROL -> NOP\n");
	return true;
}

bool SolarArrayControl::handleTelecommandSetServoAngle(const generated::SetServoAngle &setServoAngle) {
	RODOS::PRINTF("SOLAR-CONTROL -> SetServoAngle { %f }\n", (double)setServoAngle.angle);
	
	SolarArrayControl::status = 1;

	SolarArrayControl::manual_override = true;
	SolarArrayControl::desired_angle = setServoAngle.angle;

	if(SolarArrayControl::status == 1) SolarArrayControl::may_run = true;

	return true;
}

bool SolarArrayControl::handleTelecommandUnsetManualOverride() {
	RODOS::PRINTF("SOLAR-CONTROL -> UnsetManualOverride\n");
	
	SolarArrayControl::manual_override = false;
	
	return true;
}

bool SolarArrayControl::handleTelecommandStableNeeded(const generated::StableNeeded &stableNeeded) {
	RODOS::PRINTF("SOLAR-CONTROL -> StableNeeded { %d }\n", stableNeeded.is_needed);

	SolarArrayControl::mustBeStable = stableNeeded.is_needed;

	return true;
}

//Topic methods
void SolarArrayControl::handleTopicIsStableTopic(generated::IsStableTopic &message){
	SolarArrayControl::isStable = message.is_stable;
}

void SolarArrayControl::handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) {
	
	if(SolarArrayControl::status == 0) return; //if solar array is retracted -> do nothing
	if(SolarArrayControl::manual_override) return; //if in manual override -> do nothing
	if(SolarArrayControl::mustBeStable){if(!SolarArrayControl::isStable) {may_run = false;return;}} //if sat is moving -> do nothing

	//calculate angle to turn solar cells
	SolarArrayControl::desired_angle = message.position - SolarArrayControl::sun_position.offset; //TODO check if correct
	if(SolarArrayControl::desired_angle > 180) SolarArrayControl::desired_angle = -360+SolarArrayControl::desired_angle;
	else if(SolarArrayControl::desired_angle < -180) SolarArrayControl::desired_angle = 360+SolarArrayControl::desired_angle;
	
	//convert do degrees
	SolarArrayControl::desired_angle *= -1;

	//saturate desired angle
	if(SolarArrayControl::desired_angle > 85.0f)  SolarArrayControl::desired_angle = 85.0f;
	if(SolarArrayControl::desired_angle < -85.0f) SolarArrayControl::desired_angle = -85.0f;

	//if they are fixed -> call thread, else only set desired angle
	SolarArrayControl::may_run = true;

}

void SolarArrayControl::handleTopicSunPositionTopic(generated::SunPositionTopic &message) {
	SolarArrayControl::sun_position = message;
}

void SolarArrayControl::handleTopicModeTopic(generated::ModeTopic &message) {
	SolarArrayControl::current_sat_mode = message; 

	if(message.mode == 7 && message.submode == 1){
		SolarArrayControl::status = 1;
	}
}

void SolarArrayControl::handleTopicSolarCellForbiddenTopic(generated::SolarCellForbiddenTopic &message) {
	SolarArrayControl::rpi_forbids = message.is_forbidden; 
}

//self created methods
long unsigned int SolarArrayControl::angle_to_pwm(float angle){
	// for f=200 and inc=5000
	return (long unsigned int) (1500.0f + ( (1000.0f/90.0f) * angle) ); 
}

void SolarArrayControl::updateStdTM(){
	auto stdTM = this->standardTelemetry.access();
	stdTM->sunPosition = SolarArrayControl::sun_position.position;
	stdTM->status = SolarArrayControl::status;
	stdTM->angle = SolarArrayControl::current_angle;
	stdTM->manualOverride = SolarArrayControl::manual_override;
}
