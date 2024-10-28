//generated using CreateApp.sh

// App includes
#include "../include/rpi-connector.h" 

// RODOS includes
#include "hal/hal_uart.h"

// c++ includes
#include <cstring>
#include <cmath>

// UART HAL to communicate with RaspberryPI
// TX: PC10
// RX: PC11
RODOS::HAL_UART uartPi(RODOS::UART_IDX::UART_IDX4);

void RpiConnector::initialize() {
	
	// initialize the list of objects array with empty objects
	for(int i = 0; i < 10; ++i){
		RpiConnector::list_of_objects[i].ObjectID = 0;
		RpiConnector::list_of_objects[i].Position_x = 0;
		RpiConnector::list_of_objects[i].Position_y = 0;
	}

	last_alive = RODOS::NOW();
}

void RpiConnector::initRpiListenerThread(){
	
	// Initialize HAL UART 
	uartPi.init(115200);
	uartPi.config(RODOS::UART_PARAMETER_HW_FLOW_CONTROL, 1);
}


void RpiConnector::runRpiListenerThread(){
	int rxCnt = int(uartPi.read(ch, 64));
	ch[rxCnt] = 0;

	for(int i = rxCnt+1; i < 64; ++i) ch[i] = 0;

	if(rxCnt > 0){
    	corfu::Accessor acc = standardTelemetry.access();
	    acc->test_rec_len = uint8_t(rxCnt);
		//RODOS::PRINTF("MESSAGE: %s\n", ch);

		int messages_in_string = 0;
    	for(int i = 0; i < 64; ++i) if(ch[i] == '#') ++messages_in_string;
		
		if(messages_in_string <= 1) {
			if(ch[0] == 'F') decodeRPImessage(ch);
		}
		else {
			int start = 0;
			char split[65];
			for(int k = 0; k < 64; ++k) split[k] = 0;
			
			for(int j = 0; j < 64; ++j){
				split[j-start] = ch[j];
				if(ch[j] == '#'){
					if(ch[0] == 'F') decodeRPImessage(split);
					start = j + 1;
					for(int k = 0; k < 64; ++k) split[k] = 0;
				}
			}
		}
		
	}
	is_alive = (RODOS::NOW() - RpiConnector::last_alive) < 10 * RODOS::SECONDS; 

	if(!is_alive) reportAnomaly(generated::anomaly::rpi_connector::RPI_DEAD);

	corfu::Accessor acc = standardTelemetry.access();
	acc->is_alive = RpiConnector::is_alive;
}


//Telecommand methods
bool RpiConnector::handleTelecommandNOP() {
	RODOS::PRINTF("RPICONNECTOR -> NOP\n");

	//char buf[13];
	//buf[0] = 'A';
	//strncat(buf+1, (char*)dataForCalib.accelerometer, 12);
	//uartPi.write(buf, 13);
	//uartPi.write("Lblink",6);
	return true;
}

bool RpiConnector::handleTelecommandAnalyzeImage() {
	RODOS::PRINTF("RPICONNECTOR -> AnalyzeImage\n");
	uartPi.write("PAY_START#", 10);
	return true;
}

bool RpiConnector::handleTelecommandSendFoundObjects() {
	RODOS::PRINTF("RPICONNECTOR -> SendFoundObjects\n");

	corfu::Telemetry telemetry;

	for(int i = 0; i < 10; ++i) {
		listOfObjects_tm.entries[i] = RpiConnector::list_of_objects[i];
	}

	telemetry = finalizeTelemetry(listOfObjects_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);

	return true;
}

bool RpiConnector::handleTelecommandSetLED(const generated::SetLED &setLED) {
	RODOS::PRINTF("RPICONNECTOR -> SetLED {%d}\n", setLED.setOn);
	
	if(setLED.setOn) uartPi.write("LTURNON#", 8);
	else uartPi.write("LTURNOFF#", 9);

	return true;
}

bool RpiConnector::handleTelecommandStartVLC() {
	RODOS::PRINTF("RPICONNECTOR -> STARTVLC\n");

	uartPi.write("PSENDDATA#",10);

	return true;
}

//Topic methods
void RpiConnector::handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message) {
	RpiConnector::attitude = message;
}

void RpiConnector::handleTopicModeTopic(generated::ModeTopic &message) {
	RpiConnector::mode = message; //TODO maybe unnecessary?

	if(RpiConnector::mode.mode != 8) return;

	if(RpiConnector::mode.submode == 2){
		RpiConnector::mode.mode = 8;
		RpiConnector::mode.submode = 3;
		modeTopic.publish(RpiConnector::mode);

		//send message to RPI to do things
		uartPi.write("PAY_START#", 10);
	}
}

void RpiConnector::decodeRPImessage(char * message) {
	
	corfu::Telemetry telemetry;
	generated::ObjectEntry new_entry;
	uint8_t rpi_operation = 0;
	
	
	//TODO decode
	if(RODOS::strncmp(message, "F11#", 4) == 0) {
		rpiData_tm.current_op = rpi_operation = 4;

		telemetry = finalizeTelemetry(rpiData_tm);
		corfu::extendedTelemetryTopic.publish(telemetry);
	}
	else if(RODOS::strncmp(message, "FIMGOOD#", 8) == 0) {
		last_alive = RODOS::NOW();
		return;
	}
	else if(RODOS::strncmp(message, "F00#", 4) == 0) {
		// Ext telem for no object found
		rpiData_tm.current_op = 4;
		rpiData_tm.object = 0;
		rpiData_tm.pos_x = RpiConnector::attitude.position;
		rpiData_tm.pos_y = 0;

		telemetry = finalizeTelemetry(rpiData_tm);
		corfu::extendedTelemetryTopic.publish(telemetry);

		rpi_operation = 4;
	}
	else {
		if(!checkMessageOK(message)) return;

		char pos_x_buffer[11], pos_y_buffer[11];
		pos_x_buffer[10] = 0;
		pos_y_buffer[10] = 0;
		
		RODOS::strncpy(pos_x_buffer, message + 2, 10);
		RODOS::strncpy(pos_y_buffer, message + 12, 10); // TODO chech offset
		

		uint8_t objectID = message[1] - '0';
		float x_angle = (float) atof(pos_x_buffer);
		float y_angle = (float) atof(pos_y_buffer);

		//bool is_transmitting = (message[22] == 'T');
		if(message[22] == 'T') rpi_operation = 3;
		else rpi_operation = 4;

		if(objectID != 1) just_found_gs =  false;
		
		// update ext telemetry
		//rpiData_tm.current_op = (is_transmitting ? 3 : 4 );
		rpiData_tm.current_op = rpi_operation;
		rpiData_tm.object = new_entry.ObjectID = objectID;
		rpiData_tm.pos_x = new_entry.Position_x = RpiConnector::attitude.position - x_angle;
		rpiData_tm.pos_y = new_entry.Position_y = y_angle; 


		if(objectID != 9) {
			for(int i = 0; i < 10; ++i) {
				if(RpiConnector::list_of_objects[i].ObjectID == 0 || RpiConnector::list_of_objects[i].ObjectID == new_entry.ObjectID) {
					RpiConnector::list_of_objects[i] = new_entry;
					break;
				}
			}
		}

		// current message says rpi is not finished -> end
		//if(is_transmitting) return; // needed?

		if(objectID == 1 && fabs(x_angle) > 5.0f && !just_found_gs && RpiConnector::mode.mode == 8	){
			desiredStateValueTopic.publish({new_entry.Position_x});
			rpi_operation = 5; //new -> adjusting
			RpiConnector::mode.mode = 8;
			RpiConnector::mode.submode = 1;
			modeTopic.publish(RpiConnector::mode);
		}
		
		if(message[22] == 'T') {
			just_found_gs = true;
			generated::solarCellForbiddenTopic.publish({true});
		}

		rpiData_tm.current_op = rpi_operation;

		telemetry = finalizeTelemetry(rpiData_tm);
		corfu::extendedTelemetryTopic.publish(telemetry);

	}

	
	if(rpi_operation == 4 && RpiConnector::mode.mode == 8 && RpiConnector::mode.submode == 3){
		RpiConnector::mode.mode = 8;
		RpiConnector::mode.submode = 0;
		modeTopic.publish(RpiConnector::mode);

		generated::solarCellForbiddenTopic.publish({false});
	}
}

bool RpiConnector::checkMessageOK(char * message) {
	bool isF_OK = false;
	bool isTF_OK = false;
	bool isHASHTAG_OK = false;
	
	for(int i = 0; i < 24; ++i){
		if(message[i] == 0) return false;
		if(i == 0 && message[i] == 'F') isF_OK = true;
		if(i == 22 && (message[i] == 'T' || message[i] == 'F')) isTF_OK = true;;
		if(i == 23 && message[i] == '#') isHASHTAG_OK = true;

	}

	bool returnval = isF_OK && isTF_OK && isHASHTAG_OK;
	if(!returnval){
		if(mode.mode == 8 && mode.submode == 3){
			handleTelecommandAnalyzeImage();
		}
		return false;
	}
	return true;
}