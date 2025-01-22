//generated using CreateApp.sh

#include "mission.h" 
#include "rodos.h"

// Mirror stuff
#define	MaxAngle 90
#define MinAngle -90
HAL_PWM servo(PWM_IDX01); // PE11


void Mission::initialize(){
	servo.init(50, 1000); // initialize the servo with the mirror
	changeMirrorAngle(90); //and set the current angle to 90
}



//Thread methods
void Mission::initMissionThread() {

}

void Mission::runMissionThread() {
	updateStdTM();
}


//Telecommand methods
bool Mission::handleTelecommandNOP() {
	return false;
}

bool Mission::handleTelecommandChangeMode(const generated::ChangeMode &changeMode) {
	Mission::missionModes=changeMode;
	return false;
}

bool Mission::handleTelecommandChangeAngle(const generated::ChangeAngle &changeAngle) {
	Mission::changeAngle=changeAngle;
	changeMirrorAngle(Mission::changeAngle.setangle);
	return false;           
}


//Topic methods
void Mission::handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) {
	Mission::attitude=message;
}

void Mission::handleTopicProximityTopic(generated::ProximityTopic &message) {
	Mission::proximity=message;
}

void Mission::handleTopicLightSensorTopic(generated::LightSensorTopic &message) {
	Mission::light=message;
}

void Mission::handleTopicMissionModeTopic(generated::MissionModeTopic &message) { //realized i dont need this
	Mission::missionMode=message;
}	

void Mission::changeMirrorAngle(int angle){
	if(angle >MaxAngle)//check if angle is too big
		angle =MaxAngle;
	if(angle < MinAngle)
		angle = MinAngle;
	Mission::currentAngle=angle;
	angle =(angle+90) * (120-20) / (MaxAngle-MinAngle)  + 20;
	servo.write( (int) angle);
	//20 =90 degree
	//70 = 0 degree angle
	//120 = -90 degree angle	
}

void Mission::updateStdTM(){
	auto stdTM = this->standardTelemetry.access();
	stdTM->currentAngle = Mission::currentAngle;
	stdTM->currentMode = Mission::missionModes.modes;
}

