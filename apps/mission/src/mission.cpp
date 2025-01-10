//generated using CreateApp.sh

#include "mission.h" 


void Mission::initialize(){

}



//Thread methods
void Mission::initMissionThread() {

}

void Mission::runMissionThread() {

}


//Telecommand methods
bool Mission::handleTelecommandNOP() {
	return false;
}

bool Mission::handleTelecommandChangeMode(const generated::ChangeMode &changeMode) {
	Mission::missionModes=changeMode;
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

void Mission::handleTopicMissionModeTopic(generated::MissionModeTopic &message) {
	Mission::missionMode=message;
}	

