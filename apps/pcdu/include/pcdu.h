//generated using CreateApp.sh

#include <pcdu-generated/pcdu.h> 

#include "hal_gpio.h"


class Pcdu: public generated::Pcdu{
	private:
		generated::PeripheralOnOffTopic data;


	public:
	void initialize() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandSetOnOff(const generated::SetOnOff &setOnOff) override;
	bool handleTelecommandSetState(const generated::SetState &setState) override;
};
