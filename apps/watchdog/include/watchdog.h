//generated using CreateApp.sh

#include <watchdog-generated/watchdog.h> 
#include "ringbuffer.h"
#define NUM_APPS_ALIVE 12

class Watchdog: public generated::Watchdog{

	public:

	void initialize() override;

	//Thread methods
	void initWatchdogThread() override;
	void runWatchdogThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandSendAnomalyHistory() override;
	bool handleTelecommandClearAnomalies() override;
	bool handleTelecommandSetSimulatedBatteryVoltage(const generated::SetSimulatedBatteryVoltage &setSimulatedBatteryVoltage) override;
	bool handleTelecommandStopBatterySimulation() override;

	protected:
		//general iteration variable to keep trac if tune
		uint32_t iteration = 0;

		//vars to handle battery supervision
		float batteryVoltage = 0.0;
		RODOS::RingBuffer<float, 10> batterVoltageBuffer;
		float batteryAmperage = 0.0;
		float batteryVoltageToPublish = 0.0;
		bool isBatterySimulated = false;

		//vars to handle anomaly functionality
		uint16_t anomalyCounter = 0;
		uint16_t lastAnomaly = 0;
		generated::AnomalyEntry history[config::watchdog::ANOMALY_HISTORY_SIZE];
		uint8_t next_history_ptr;

		//vars to handle AppIsAlive functionality
		corfu::BitArray<NUM_APPS_ALIVE> appStatus;
		corfu::Alive previous_alives[NUM_APPS_ALIVE]; // length should be same as bit array

		//var for cpu load
		float cpu_percentage = 0.0;

		//structs for topics -> send
		generated::BatteryVoltageTopic bvt;
		corfu::Alive watchdog_alive;

		//structs for topics -> receive

		//own methods
		void readAmpMeter();
		void readVoltMeter();
		void updateStdTM();

};
