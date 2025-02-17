//generated using CreateApp.sh

#include "mission.h" 
#include "rodos.h"

// Mirror stuff the mirror accepts angles from 0 to 90 degrree
#define	MaxAngle 100
#define MinAngle 0
HAL_PWM servo(PWM_IDX01); // PE11



//offset for the sonsors so that the coordinate Frame matches the IMU
#define PROXIMITYSENSOROFFSET 90
#define LIGHTSENSOROFFSET -90
#define OFFSET_MIRROR 0

#define rotation 0
#define d2 93 //D2 in mm
#define h1 136 //h1 in mm
#define h3 68 //distance h3 measured in mm
#define h5 26 //h2 in mm
#define threshold 3

//int time1;
void Mission::initialize(){
	servo.init(50, 1000); // initialize the servo with the mirror
	changeMirrorAngle(90); //and set the current angle to 90
}

int x = 0;
//Thread methods
void Mission::initMissionThread() {
	time=RODOS::NOW(); 
}

void Mission::runMissionThread() {
	updateStdTM();
	//if(RODOS::NOW()-time>10*SECONDS){
	//	changeMirrorAngle(45);
	//}else
	//	changeMirrorAngle(90);
}


//Telecommand methods
bool Mission::handleTelecommandNOP() {
	return false;
}

float Mission::targetReaction(float x, float y){
	if(x-y<-180){
		return (x+360)/2+y/2;
	} else if(x-y >180){
		return (x-360)/2+y/2;
	} else	
		return (x)/2+y/2;
    }

float Mission::mod(float in){
	if( in < -180)
		in += 360;
	else if( in > 180)
		in -= 360;
	return in;
}

inline void Mission::rotate_start(){
	generated::ModeTopic mode;
	attitude_start= mod(Mission::attitude.position + 10.0) ;
	time_start= RODOS::NOW();
	mode.mode=2;
	mode.submode=rotationspeed;
	modeTopic.publish(mode);
	collecting_max = true;
}

inline void Mission::rotate_end(){
	generated::ModeTopic mode;
	mode.mode=2;
	mode.submode=0;
	modeTopic.publish(mode);
	switch (missionModes.modes){
		default:
			break;
		case 1:
			break;
		case 2:
			mode.mode=1;
			mode.submode=Att_light;
			modeTopic.publish(mode);
			break;
		case 3:
			mode.mode=1;
			mode.submode=Att_obj;
			modeTopic.publish(mode);
			break;
		case 4:
			mode.mode=1;
			mode.submode=targetReaction(Att_light , mod(Att_obj ));
			modeTopic.publish(mode);
			changeMirrorAngle(calculateMirrorAngle());
			break;
		case 5:
			mode.mode=1;
			mode.submode=targetReaction(Att_light , mod(Att_obj ));
			modeTopic.publish(mode);
			changeMirrorAngle(calculateMirrorAngle());
			break;  
	}
	collecting_max = false;
}

bool Mission::handleTelecommandChangeMode(const generated::ChangeMode &changeMode) {
	Mission::missionModes=changeMode;

	generated::ModeTopic mode;
	
	if(!isInMission){
		isInMission=true;
		switch (missionModes.modes) {
			case 0:
				break;
			case 5:
			case 1:
				Mission::rotate_start();
				break;
			default:
				if(Mission::Att_light>500)
					Mission::rotate_start();
				else
					rotate_end();
				break;

        }
		isInMission=false;
	}
	else if(missionModes.modes == 0){
		isInMission=false;
		collecting_max=false;
		rotate_end();
	}
	return false;
}

bool Mission::handleTelecommandChangeAngle(const generated::ChangeAngle &changeAngle) {
	Mission::changeAngle=changeAngle;
	changeMirrorAngle(Mission::changeAngle.setangle);
	return false;           
}

bool Mission::handleTelecommandSetMinDist(const generated::SetMinDist& setMinDist) {
	Mission::nearest=setMinDist.dist;
	changeMirrorAngle(calculateMirrorAngle());
	return false;           
}

bool Mission::handleTelecommandSetSunConstants(const generated::SetSunConstants& setSunConstants) {
	sun_dist = setSunConstants.distance;
	sun_height = setSunConstants.height;
	return false;
}

bool Mission::handleTelecommandSetRotationSpeed(const generated::SetRotationSpeed& rotationspeed2){
	rotationspeed=rotationspeed2.speed;
	return false;
}

bool Mission::handleTelecommandMirrorTracking(const generated::MirrorTracking& mirrorRotation){
	isTracking = mirrorRotation.isTracking;
	return false;
}

bool Mission::handleTelecommandSetMirrorOffset(const generated::SetMirrorOffset& setMirrorOffset) {
	mirror_offset = setMirrorOffset.offset;
	return false;
}

//Topic methods
void Mission::handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) {
	Mission::attitude=message;
	if(isTracking)
		changeMirrorAngle(calculateMirrorAngle());
}

void Mission::handleTopicProximityTopic(generated::ProximityTopic &message) {
	Mission::proximity=message;
	if(collecting_max){
		if(!check_rotation_end())
		if(proximity.distance<nearest && proximity.distance > 0) { //had some bs where this was 0 so hope to catch the bs with this
			nearest=proximity.distance;
			Att_obj=mod(attitude.position+PROXIMITYSENSOROFFSET+mirror_offset);
		}
	}
}

void Mission::handleTopicLightSensorTopic(generated::LightSensorTopic &message) {
	Mission::light=message;
	if(collecting_max){
		if(!check_rotation_end())
		if(light.intensity>brightest) {
			brightest=light.intensity;
			Att_light=mod(attitude.position+LIGHTSENSOROFFSET+mirror_offset);
		}
	}
}

bool Mission::check_rotation_end(){
	if ( (RODOS::NOW() - time_start > 10*RODOS::SECONDS) && (abs(Mission::attitude.position - attitude_start)<5)){
			rotate_end();
			return true;
		}  
	return false;
}

void Mission::handleTopicMissionModeTopic(generated::MissionModeTopic &message) { //realized i dont need this
	Mission::missionMode=message;
}	


int Mission::calculateMirrorAngle(){
	float d1=nearest*10;
	sunAngle = atan2(sun_height,sun_dist)*180/M_PI;
	objAngle = atan2(d1,115)*180/M_PI;
	gamma = (90-objAngle);

	return (int) (90-0.5*(gamma-sunAngle)) - (int) attitude.roll - 6;
	//return (90 - winkel + winkel2 )/2;

	/*int beta=90, betamin =90;
	float omegadiffmin =90;
	float omega=0;
	float omegasoll=90;
	float nu = tan(cos(rotation/360*M_PI)*sin(attitude.roll/360*M_PI)+sin(rotation/360*M_PI)*sin(attitude.pitch/360*M_PI));
	while (true){
		beta = beta- 2;
		float q1= sqrt((d1+d2-h1*sin(nu))*(d1+d2-h1*sin(nu))
						+(h1*cos(nu)-h5)*(h1*cos(nu)-h5));
		float q2= sqrt((sun_dist+d2-h1*sin(nu)-h3*cos(beta-nu))*(sun_dist+d2-h1*sin(nu)-h3*cos(beta-nu))
						+(sun_height-h1*cos(nu)+h5-h3 *sin(beta-nu))*(sun_height-h1*cos(nu)+h5-h3 *sin(beta-nu)));
		omegasoll = asin( (q2*q2+h3*h3-q1*q1)/(2*q2*h3));
		omega = beta-nu -tan((sun_height - h1*cos(nu)-h3*sin(beta-nu)/(sun_dist+d2-h1*sin(nu)-h3*cos(beta-nu))));
		if(abs(omega-omegasoll)<omegadiffmin){
			omegadiffmin=abs(omega-omegasoll);
			betamin=beta;
		}
		if(abs(omega-omegasoll)<threshold )
			return beta;
		if(beta<45)
			return betamin;
		return (int) tan(beta/d1)-nu;
	}*/
}

void Mission::changeMirrorAngle(int angle){
	if(angle >MaxAngle)//check if angle is too big
		angle =MaxAngle;
	if(angle < MinAngle)
		angle = MinAngle;
	currentAngle=angle;
	RODOS::PRINTF("changed angle to %d\n", angle);
	angle= -angle;
	angle =(angle+90) * (120-20) / (180)  + 20;

	servo.write(angle);
	
	//20 =90 degree
	//70 = 0 degree angle
	//120 = -90 degree angle	
}

void Mission::updateStdTM(){
	if(RODOS::NOW() - time > 1 * RODOS::SECONDS){
        time=RODOS::NOW();
		auto stdTM = this->standardTelemetry.access();
		stdTM->currentAngle = Mission::currentAngle;
		stdTM->currentMode = Mission::missionModes.modes;
		stdTM->isInMission = Mission::isInMission;
		stdTM->attitudeLight = Mission::Att_light;
		stdTM->attitudeObject = Mission::Att_obj;
		stdTM->distanceObject = Mission::nearest;
		stdTM->intensityLight = Mission::brightest;
	}
}

