//generated using CreateApp.sh

#include <sensor-collector-generated/sensor-collector.h> 

#define AccADDR 0x6B //also includes gyro
#define MagADDR 0x1E

#define R2D 57.2958
#define CALIB_TIME 30

#include "rodos.h"
#include "hal/hal_adc.h"
#include "hal/hal_i2c.h"
#include "math.h"
#include <cfloat>

struct calibDataMagn {
		float xMin, xMax, yMin, yMax, zMin, zMax;
};

struct calibDataSS {
		float xMin, xMax, yMin, yMax, zMin, zMax, qMin, qMax;
};

class SensorCollector: public generated::SensorCollector{

	public:

	int64_t intervalIMU = 10*RODOS::MILLISECONDS; 
	int64_t intervalSunSensors = 50*RODOS::MILLISECONDS; 
	int64_t intervalPowerMeter = 1000*RODOS::MILLISECONDS; 

	int64_t lastRunIMU;
	int64_t lastRunSunSensors;
	int64_t lastRunPowerMeter;

	bool is_calibratingMagn = false;
	int64_t calibStartedMagnAt;
	struct calibDataMagn calibDataMagn = {-687.000f, 231.000f, -499.000f, 543.000f, -1246.000f, -0.895f};

	bool IMUOnOff = true;
	bool SunSensorsOnOff = true;
	int64_t ssPrintoutTime;
	struct calibDataSS calibDataSS = {0.116f, 0.195f, 0.124f, 0.193f, 0.129f, 0.220f, 0.144f, 0.204f};
	bool is_callibratingSS = false;
	int64_t calibSSStartedAt;

	float ss0offsetAngle = 0.0f;
	float ss0offsetAngleSum = 0.0f;
	bool is_callibratingSS0Offset = false;
	int64_t callibSS0OffsetStartedAt;
	int32_t ss0offsetCounter = 0;

	bool calib_gyro = false;
	int calib_gyro_counter = 0;
	float calib_gyro_sums[3];

	corfu::Telemetry telemetry;

	struct PowerData {
		float volts, amps, motorAmps;
	};
	
	struct PowerData latestPowerData;
	float latestSunSensorData[4];
	struct generated::ImuDataTopic latestIMUData;

	float latestSSAngleValue;
	struct generated::ModeTopic currentMode;

	void initialize() override;

	//Thread methods
	void initSensorCollectorThread() override;
	void runSensorCollectorThread() override;

	void initSensorExtTelemetryThread() override;
	void runSensorExtTelemetryThread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
	bool handleTelecommandSetCollectionInterval(const generated::SetCollectionInterval &setCollectionInterval) override;
	bool handleTelecommandSendCollectionIntervals() override;
	bool handleTelecommandCallibMagnetometer() override;
	bool handleTelecommandCallibSS() override;
	bool handleTelecommandCallibSS0Offset() override;
	bool handleTelecommandCallibGyro() override;
	bool handleTelecommandSendCallibValues() override;

	//Topic methods
	void handleTopicPeripheralOnOffTopic(generated::PeripheralOnOffTopic &message) override;
	void handleTopicModeTopic(generated::ModeTopic &message) override;

	//Other methods
	void collectIMU();
	void collectSunSensors();
	void collectPowerMeter();
};
