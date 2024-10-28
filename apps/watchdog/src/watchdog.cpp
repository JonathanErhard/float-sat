//generated using CreateApp.sh

#include "watchdog.h" 

#include "rodos.h"
#include "hal_adc.h"
#include "hal_gpio.h"

#include <cmath>

#define BATTERY_ADC_REF  17.846f // was 17.0f //change this according to electrical design
#define BATTERY_ADC_RES 4095.0f
#define BATTERY_ADC_CHANNEL_1 RODOS::ADC_CHANNEL::ADC_CH_011 //volt reading

#define BATTERY_AMP_REF 3.0f
#define BATTERY_AMP_FILTERLENGTH 10
#define BATTERY_ADC_CHANNEL_2 RODOS::ADC_CHANNEL::ADC_CH_012 //amp reading

#define BATTERY_THRESHHOLD_LOW 13.5f
#define BATTERY_THRESHHOLD_CRITICAL 13.2f
#define BATTERY_FILTER_ITERATIONS 10

#define ANOMALY_TIMEOUT 5*60 //5 minutes

HAL_ADC watchdog_battery_adc(RODOS::ADC_IDX::ADC_IDX3);

HAL_GPIO watchdog_alive_led(RODOS::GPIO_PIN::GPIO_060);

void Watchdog::initialize(){
	for(int i = 0; i < 10; i++)
	batterVoltageBuffer.put(0.0f);

}


//Thread methods
void Watchdog::initWatchdogThread() {
	watchdog_battery_adc.config(RODOS::ADC_PARAMETER_TYPE::ADC_PARAMETER_RESOLUTION, 12);
	watchdog_battery_adc.init(BATTERY_ADC_CHANNEL_1);
	watchdog_battery_adc.init(BATTERY_ADC_CHANNEL_2);

	watchdog_alive_led.init(1,1,0);

	for(uint8_t i = 1; i < NUM_APPS_ALIVE; ++i) appStatus.setBit(i, true);
	appStatus.setBit(0, false);

	for(uint8_t i = 0; i < NUM_APPS_ALIVE; ++i) previous_alives[i] = corfu::Alive(i, RODOS::END_OF_TIME);

	watchdog_alive = corfu::Alive(appId, RODOS::NOW() + 5*SECONDS);

}

void Watchdog::runWatchdogThread() {
	Watchdog::iteration++;

	watchdog_alive_led.setPins(~watchdog_alive_led.readPins());

	//handle battery things
	Watchdog::readVoltMeter();
	Watchdog::readAmpMeter();
	
	if(Watchdog::batteryVoltage <= BATTERY_THRESHHOLD_LOW && Watchdog::batteryVoltage > BATTERY_THRESHHOLD_CRITICAL) reportAnomaly(generated::anomaly::watchdog::BATTERY_VOLTAGE_LOW);
	if(Watchdog::batteryVoltage <= BATTERY_THRESHHOLD_CRITICAL) reportAnomaly(generated::anomaly::watchdog::BATTERY_VOLTAGE_CRITICAL);

	if(!(Watchdog::isBatterySimulated)) Watchdog::batteryVoltageToPublish = Watchdog::batteryVoltage;
	Watchdog::bvt.voltage = Watchdog::batteryVoltageToPublish;
	batteryVoltageTopic.publish(Watchdog::bvt);

	//handle appIsAlive
	corfu::Alive currentAlive;
	while(corfuAppIsAliveTopicFifo.get(currentAlive)){
		previous_alives[currentAlive.id] = currentAlive;
		appStatus.setBit(currentAlive.id, true);
	}
	

	for(uint8_t i = 0; i < NUM_APPS_ALIVE; ++i){
		if(previous_alives[i].timeout == RODOS::END_OF_TIME) continue;
		if(previous_alives[i].timeout < RODOS::NOW()){
			appStatus.setBit(i, false);
			reportAnomaly(generated::anomaly::watchdog::SOME_APP_NOT_ALIVE);
		}
	}


	//handle anmoalies
	corfu::Anomaly currentAnomaly;
	generated::AnomalyEntry currentEntry;

	while(corfuAnomalyTopicFifo.get(currentAnomaly)){
		//copy values from topic to internal struct
		currentEntry.anomaly = currentAnomaly.id;
		currentEntry.time = Watchdog::iteration;

		//find anomaly in history and check if timeout is ok
		bool found_in_timeout = false;
		for(int i = 0; i < config::watchdog::ANOMALY_HISTORY_SIZE; ++i){
			if(Watchdog::history[i].anomaly == currentEntry.anomaly && ((Watchdog::history[i].time + ANOMALY_TIMEOUT) >= Watchdog::iteration)){
				found_in_timeout = true;
				break;
			} 
		}

		//if anomaly is still in timeout, ignore
		if(found_in_timeout == true) continue;

		//add anomaly to history
		Watchdog::history[Watchdog::next_history_ptr] = currentEntry;
		if(++(Watchdog::next_history_ptr) >= config::watchdog::ANOMALY_HISTORY_SIZE) Watchdog::next_history_ptr = 0;
	
		//set internal vars
		Watchdog::anomalyCounter++;
		Watchdog::lastAnomaly = currentEntry.anomaly;
	}

	//handle cpu load
	Watchdog::cpu_percentage = 100 * RODOS::getCpuLoad();

	//update standard telemetry
	Watchdog::updateStdTM();

	//send alive
	watchdog_alive.timeout = RODOS::NOW() + 5*SECONDS;
	corfuAppIsAliveTopic.publish(watchdog_alive);
}


//Telecommand methods
bool Watchdog::handleTelecommandNOP() {
	RODOS::PRINTF("WATCHDOG -> NOP\n");
	return true;
}

bool Watchdog::handleTelecommandSendAnomalyHistory() {
	RODOS::PRINTF("WATCHDOG -> SendAnomalyHistory\n");
	
	corfu::Telemetry telemetry;

	for(int i = 0; i < 10; ++i){
		anomalyHistory_tm.entries[i] = history[i];
	}

	telemetry = finalizeTelemetry(anomalyHistory_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);

	return true;
}

bool Watchdog::handleTelecommandClearAnomalies() {
	RODOS::PRINTF("WATCHDOG -> ClearAnomalies\n");

	Watchdog::anomalyCounter = 0;
	Watchdog::next_history_ptr = 0;

	generated::AnomalyEntry emptyEntry;
	for(int i = 0; i < 10; ++i){
		Watchdog::history[i] = emptyEntry;
	}

	return true;
}

bool Watchdog::handleTelecommandSetSimulatedBatteryVoltage(const generated::SetSimulatedBatteryVoltage &setSimulatedBatteryVoltage) {
	RODOS::PRINTF("WATCHDOG -> SetSimulatedBatteryVoltage { %f }", (double)setSimulatedBatteryVoltage.voltage);

	Watchdog::isBatterySimulated = true;
	Watchdog::batteryVoltageToPublish = setSimulatedBatteryVoltage.voltage;

	return true;
}

bool Watchdog::handleTelecommandStopBatterySimulation() {
	RODOS::PRINTF("WATCHDOG -> StopBatterySimulation");

	Watchdog::isBatterySimulated = false;

	return true;	
}

//self created methods
void Watchdog::readVoltMeter() {
	float sum_of_voltage = 0;
	for(int i = 0; i < BATTERY_FILTER_ITERATIONS; ++i){
		sum_of_voltage += watchdog_battery_adc.read(BATTERY_ADC_CHANNEL_1) / BATTERY_ADC_RES * BATTERY_ADC_REF;
	}
	Watchdog::batterVoltageBuffer.put(sum_of_voltage / BATTERY_FILTER_ITERATIONS);
	sum_of_voltage = 0;
	for(int i = 0; i < 10; ++i){
		sum_of_voltage += Watchdog::batterVoltageBuffer.vals[i];
	}
	Watchdog::batteryVoltage = sum_of_voltage/10 -0.8f;
}

void Watchdog::readAmpMeter() {
	float avg = 0.0f;
	for(int i = 0; i < BATTERY_AMP_FILTERLENGTH; ++i) {
		avg += watchdog_battery_adc.read(BATTERY_ADC_CHANNEL_2) / BATTERY_ADC_RES * BATTERY_AMP_REF;
	}
	float volts = avg / BATTERY_AMP_FILTERLENGTH;

	// Note, if readings become inacurate -> redo this table
	//                               0.000A  0.500A  1.000A  1.500A  2.000A  2.500A  3.000A  3.500A  4.000A  4.500A  5.000A
	static float voltReadings[11] = {2.594f, 2.496f, 2.400f, 2.309f, 2.210f, 2.114f, 2.022f, 1.929f, 1.833f, 1.738f, 1.647f};

	int index = 0;
	//find index where reading is between this and the next
	for(int i = 0; i < 10; i++){
		// if its around 0.003V of one simply return the amps corrosponding to the index
		if(float(fabs(volts - voltReadings[i])) < 0.003f){
			Watchdog::batteryAmperage = (float(i) * 0.5f);
			return;	
		}
		//if its between this and the next, save the index and break
		if(volts < voltReadings[i] && volts > voltReadings[i+1]) {
			index = i;
			break;
		}
	}
	//calculate the gradient for values between index and index + 1
	float gradient = 0.5f/(voltReadings[index+1] - voltReadings[index]);

	// calculate the amps resulting from that and return it
	Watchdog::batteryAmperage = float(index) * 0.5f + (volts - voltReadings[index]) * gradient;
}

void Watchdog::updateStdTM(){
	auto stdTM = this->standardTelemetry.access();
	stdTM->iteration = Watchdog::iteration;
	stdTM->batteryVoltage = Watchdog::batteryVoltage;
	stdTM->batteryAmperage = Watchdog::batteryAmperage;
	stdTM->isBatterySimulated = Watchdog::isBatterySimulated;
	stdTM->anomalyCounter = Watchdog::anomalyCounter;
	stdTM->lastAnomaly = Watchdog::lastAnomaly;
	stdTM->appStatus = Watchdog::appStatus;
	stdTM->cpuload = Watchdog::cpu_percentage;
}