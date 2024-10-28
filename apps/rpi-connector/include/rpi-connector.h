//generated using CreateApp.sh
#pragma once
#include <rpi-connector-generated/rpi-connector.h> 

class RpiConnector: public generated::RpiConnector {

	protected:
		generated::ObjectEntry list_of_objects[10]; // array to save all found objects

		// Struct for topics
		generated::AttitudeDeterminationTopic attitude;
		generated::ModeTopic mode;

		int64_t last_alive;
		bool is_alive;
		bool just_found_gs;

	public:
	char ch[65];
	void initialize() override;

	//Thread methods
	void initRpiListenerThread() override;
	void runRpiListenerThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandAnalyzeImage() override;
	bool handleTelecommandSendFoundObjects() override;
	bool handleTelecommandSetLED(const generated::SetLED &setLED) override;
	bool handleTelecommandStartVLC() override;

	//Topic methods
	void handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) override;
	void handleTopicModeTopic(generated::ModeTopic &message) override;
	
	//own methods
	void decodeRPImessage(char * message);
	bool checkMessageOK(char * message);

};
