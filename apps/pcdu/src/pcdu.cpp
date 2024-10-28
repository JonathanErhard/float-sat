//generated using CreateApp.sh

#include "../include/pcdu.h" 

//If this is too much mem/CPU change to a pin group
RODOS::HAL_GPIO powerIMU(RODOS::GPIO_020); //PB4 pin

RODOS::HAL_GPIO raspiOnOff(RODOS::GPIO_021); //PB5 pin

RODOS::HAL_GPIO powerSunSensor(RODOS::GPIO_038); //PC6 pin

void Pcdu::initialize(){
	powerIMU.init(1,1,1);

	powerSunSensor.init(1,1,1);

	data.state.setBit(0,true);
	data.state.setBit(1,true);
	data.state.setBit(2,true);
}


//Telecommand methods
bool Pcdu::handleTelecommandNOP() {
	RODOS::PRINTF("PCDU -> NOP\n");

	return true;
}

bool Pcdu::handleTelecommandSetOnOff(const generated::SetOnOff &setOnOff) {
	RODOS::PRINTF("PCDU -> SetOnOff { %d, %d }\n", setOnOff.powerline, setOnOff.setOn);

	if(setOnOff.powerline == 0){
		powerIMU.setPins(setOnOff.setOn);
	}
	else if(setOnOff.powerline == 1){
		powerSunSensor.setPins(setOnOff.setOn);
	}
	if(setOnOff.powerline == 2){
		raspiOnOff.setPins(setOnOff.setOn);
	}


	data.state.setBit(setOnOff.powerline, setOnOff.setOn);
	peripheralOnOffTopic.publish(data);

	return true;
}

bool Pcdu::handleTelecommandSetState(const generated::SetState &setState) {
	RODOS::PRINTF("PCDU -> SetState\n");

	powerIMU.setPins(setState.state.getBit(0));
	powerSunSensor.setPins(setState.state.getBit(1));
	raspiOnOff.setPins(setState.state.getBit(2));
		
	for(uint32_t i = 0; i < 3; i++){
		data.state.setBit(i, setState.state.getBit(i));
	}

	peripheralOnOffTopic.publish(data);
	
	return true;
}

