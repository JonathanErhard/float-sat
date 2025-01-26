// generated using CreateApp.sh

#include "control-master.h"
#include "rodos.h"

#define	MaxAngle
#define MinAngle

HAL_PWM servo(PWM_IDX01); // PE11
int angle = 20;
bool dir = 0;

void ControlMaster::initialize()
{
}

// Thread methods
void ControlMaster::initServoThread()
{
	servo.init(50, 1000);
}



void ControlMaster::runServoThread()
{
	dir ? angle += 5 : angle -= 5;
	if (angle > 40 || angle < 20)
		dir = !dir;
	PRINTF("%d\n", dir);
	
	//servo.write(125);
	//20 =90 degree
	//70 = 0 degree angle
	//120 = -90 degree angle
	
}
int ControlMaster::calculateAngle(float angle){
	if(angle >MaxAngle)//check if angle is too big
		angle =MaxAngle;
	if(angle < MinAngle)
		angle = MinAngle

	angle =(angle+90) * (120-20) / (MaxAngle-MinAngle)  + 20;

	return (int) angle;
	
}

// Telecommand methods
bool ControlMaster::handleTelecommandNOP()
{
	return false;
}


