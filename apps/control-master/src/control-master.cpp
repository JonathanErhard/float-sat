// generated using CreateApp.sh

#include "control-master.h"
#include "rodos.h"

HAL_PWM servo(PWM_IDX01); // PE11
int angle = 0;
bool dir = 0;

void ControlMaster::initialize()
{
}

// Thread methods
void ControlMaster::initServoThread()
{
	servo.init(50, 4000);
}

unsigned int calculatePWM(float Angle)
{
	return (unsigned int)(1920 - 2 * Angle); // orig:4
}

void ControlMaster::runServoThread()
{
	dir ? angle += 1 : angle -= 1;
	if (angle > 50 || angle < 0)
		dir = !dir;
	// PRINTF("%d\n", angle);
	servo.write(calculatePWM(angle));
}

void ControlMaster::handleTopicLightSensorTopic(generated::LightSensorTopic &message)
{
	auto sun_v = message.intensity;
}

// Telecommand methods
bool ControlMaster::handleTelecommandNOP()
{
	return false;
}
