//generated using CreateApp.sh

#include "../include/sensor-collector.h" 
/* #region IMU Constants*/
RODOS::HAL_I2C anglesIMU(RODOS::I2C_IDX::I2C_IDX2); //PB10 & PB11

//Buffers for data to be read into
uint8_t DATA_L[1] = {0};
uint8_t DATA_H[1] = {0};

/*
*  Buffers for all processed values
*/

//GYRO
float GYR_CALIB_VALS[3] = {1.26502215f, -0.03441086f, 0.77206468f}; //fill through external programm!
float GYR_REAL_VALS[3] = {0.0f, 0.0f, 0.0f};
int16_t GYR_RAW_VALS[3] = {0, 0, 0};

//ACCELEROMETER
float ACC_CALIB_VALS[3] = {-0.10875375f, -0.01491124f, 0.03084271f}; //fill through external programm!
float ACC_REAL_VALS[3] = {0.0f, 0.0f, 0.0f};
int16_t ACC_RAW_VALS[3] = {0, 0, 0};

//MAGNETOMETER
float MAG_REAL_VALS[3] = {0.0f, 0.0f, 0.0f};
int16_t MAG_RAW_VALS[3] = {0, 0, 0};


/*
*  REGISTER ADDRESSES
*/

//GYRO
uint8_t GYR_X_L[1] = {0x18};
uint8_t GYR_X_H[1] = {0x19};
uint8_t GYR_Y_L[1] = {0x1A};
uint8_t GYR_Y_H[1] = {0x1B};
uint8_t GYR_Z_L[1] = {0x1C};
uint8_t GYR_Z_H[1] = {0x1D};

//ACCELLEROMETER
uint8_t ACC_X_L[1] = {0x28};
uint8_t ACC_X_H[1] = {0x29};
uint8_t ACC_Y_L[1] = {0x2A};
uint8_t ACC_Y_H[1] = {0x2B};
uint8_t ACC_Z_L[1] = {0x2C};
uint8_t ACC_Z_H[1] = {0x2D};

//MAGNETOMETER
uint8_t MAG_X_L[1] = {0x28};
uint8_t MAG_X_H[1] = {0x29};
uint8_t MAG_Y_L[1] = {0x2A};
uint8_t MAG_Y_H[1] = {0x2B};
uint8_t MAG_Z_L[1] = {0x2C};
uint8_t MAG_Z_H[1] = {0x2D};

/* #endregion */

#define ADCRes 4095.0f // ADC full scale resolution of 12 bits = 2^12-1 = 4095
#define ADCRef 3000.0f // ADC adc reference voltage = 3V = 3000mV

/* #region SolarSensor Constants*/
HAL_ADC adcSolarSensor(RODOS::ADC_IDX::ADC_IDX1); // A single ADC unit, able to measure voltages from different Pins

#define solarPin1 RODOS::ADC_CHANNEL::ADC_CH_004 // PA4 pin
#define solarPin2 RODOS::ADC_CHANNEL::ADC_CH_013 // PC3 pin
#define solarPin3 RODOS::ADC_CHANNEL::ADC_CH_006 // PA6 pin
#define solarPin4 RODOS::ADC_CHANNEL::ADC_CH_007 // PA7 pin
/* #endregion */

/* #region SolarPower Constants*/
HAL_ADC adcPower(RODOS::ADC_IDX::ADC_IDX2); // A single ADC unit, able to measure voltages from different Pins

#define panelVoltPin RODOS::ADC_CHANNEL::ADC_CH_008 // PB0 pin
#define panelAmpPin RODOS::ADC_CHANNEL::ADC_CH_015 // PC5 pin
#define motorAmpPin RODOS::ADC_CHANNEL::ADC_CH_009 // PB1 pin

/* #endregion */

void SensorCollector::initialize(){

}

void initIMU(){
	anglesIMU.init(400000);
	uint8_t INIT_REG_GYR[2] = {0x10, 0b10011000};
	uint8_t INIT_REG_ACC[2] = {0x20, 0b10000011}; //Address: 0x20, value 0b10000011 - see LuRI Lab for more info
	uint8_t INIT_REG_MAG_1[2] = {0x20, 0b00011100};
	uint8_t INIT_REG_MAG_2[2] = {0x21, 0b01100000};
	uint8_t INIT_REG_MAG_3[2] = {0x22, 0b00000000};
	
	anglesIMU.write(AccADDR, INIT_REG_GYR, 2);
	anglesIMU.write(AccADDR, INIT_REG_ACC, 2);
	anglesIMU.write(MagADDR, INIT_REG_MAG_1, 2);
	anglesIMU.write(MagADDR, INIT_REG_MAG_2, 2);
	anglesIMU.write(MagADDR, INIT_REG_MAG_3, 2);
}

void initSolarSensor(){
	adcSolarSensor.config(RODOS::ADC_PARAMETER_TYPE::ADC_PARAMETER_RESOLUTION, 12);
	adcSolarSensor.init(solarPin1);
	adcSolarSensor.init(solarPin2);
	adcSolarSensor.init(solarPin3);
	adcSolarSensor.init(solarPin4);
}

void initPower(){
	adcPower.config(RODOS::ADC_PARAMETER_TYPE::ADC_PARAMETER_RESOLUTION, 12);
	adcPower.init(panelVoltPin);
	adcPower.init(panelAmpPin);
}

//Thread methods
void SensorCollector::initSensorCollectorThread() {
	int64_t now = RODOS::NOW();
	lastRunIMU = now;
	lastRunSunSensors = now;
	lastRunPowerMeter = now;
	ssPrintoutTime = now;

	initIMU(); //TODO TURN ON WHEN IMU IS CONNECTED!!
	initSolarSensor();
	initPower();
}

void SensorCollector::collectIMU(){
	/* #region ACC */
	anglesIMU.writeRead(AccADDR, ACC_X_L, 1, DATA_L, 1);
	anglesIMU.writeRead(AccADDR, ACC_X_H, 1, DATA_H, 1);
	ACC_RAW_VALS[0] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	anglesIMU.writeRead(AccADDR, ACC_Y_L, 1, DATA_L, 1);
	anglesIMU.writeRead(AccADDR, ACC_Y_H, 1, DATA_H, 1);
	ACC_RAW_VALS[1] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	anglesIMU.writeRead(AccADDR, ACC_Z_L, 1, DATA_L, 1);
	anglesIMU.writeRead(AccADDR, ACC_Z_H, 1, DATA_H, 1);
	ACC_RAW_VALS[2] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	for(int j = 0; j < 3; j++){
		ACC_REAL_VALS[j] = (0.061f/1000) * ACC_RAW_VALS[j] - ACC_CALIB_VALS[j];
	}
	/* #endregion */

	/* #region GYRO */
	anglesIMU.writeRead(AccADDR, GYR_X_L, 1, DATA_L, 1);
	anglesIMU.writeRead(AccADDR, GYR_X_H, 1, DATA_H, 1);
	GYR_RAW_VALS[0] = DATA_L[0] + int16_t((DATA_H[0] << 8));
	

	anglesIMU.writeRead(AccADDR, GYR_Y_L, 1, DATA_L, 1);
	anglesIMU.writeRead(AccADDR, GYR_Y_H, 1, DATA_H, 1);
	GYR_RAW_VALS[1] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	anglesIMU.writeRead(AccADDR, GYR_Z_L, 1, DATA_L, 1);
	anglesIMU.writeRead(AccADDR, GYR_Z_H, 1, DATA_H, 1);
	GYR_RAW_VALS[2] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	for(int j = 0; j < 3; j++){
		GYR_REAL_VALS[j] = (70.0f/1000) * GYR_RAW_VALS[j] - GYR_CALIB_VALS[j];
	}
	/* #endregion */

	/* #region MAGNO */
	anglesIMU.writeRead(MagADDR, MAG_X_L, 1, DATA_L, 1);
	anglesIMU.writeRead(MagADDR, MAG_X_H, 1, DATA_H, 1);
	MAG_RAW_VALS[0] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	anglesIMU.writeRead(MagADDR, MAG_Y_L, 1, DATA_L, 1);
	anglesIMU.writeRead(MagADDR, MAG_Y_H, 1, DATA_H, 1);
	MAG_RAW_VALS[1] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	anglesIMU.writeRead(MagADDR, MAG_Z_L, 1, DATA_L, 1);
	anglesIMU.writeRead(MagADDR, MAG_Z_H, 1, DATA_H, 1);
	MAG_RAW_VALS[2] = DATA_L[0] + int16_t((DATA_H[0] << 8));

	if(is_calibratingMagn){
		for(int j = 0; j < 3; j++){
			MAG_REAL_VALS[j] = MAG_RAW_VALS[j];
			//else MAG_REAL_VALS[j] = ((0.14f/1000) * MAG_RAW_VALS[j] - MAG_CALIB_MIN[j]) / (MAG_CALIB_MAX[j] - MAG_CALIB_MIN[j]) * 2 - 1;
		}
	}
	else {
		MAG_REAL_VALS[0] = ((MAG_RAW_VALS[0] - calibDataMagn.xMin) / (calibDataMagn.xMax - calibDataMagn.xMin))*2-1 ;
		MAG_REAL_VALS[1] = ((MAG_RAW_VALS[1] - calibDataMagn.yMin) / (calibDataMagn.yMax - calibDataMagn.yMin))*2-1;
		MAG_REAL_VALS[2] = ((MAG_RAW_VALS[2] - calibDataMagn.zMin) / (calibDataMagn.zMax - calibDataMagn.zMin))*2-1;

	}
	/* #endregion */

	latestIMUData = {
		ACC_REAL_VALS[0],ACC_REAL_VALS[1],ACC_REAL_VALS[2],
		GYR_REAL_VALS[0],GYR_REAL_VALS[1],GYR_REAL_VALS[2],
		MAG_REAL_VALS[0],MAG_REAL_VALS[1],MAG_REAL_VALS[2]
	};

	imuDataTopic.publish(latestIMUData);
}

#define SSReadNum 10
constexpr float ADCMULT = 1.0f/(ADCRes*SSReadNum);
void SensorCollector::collectSunSensors(){
	uint16_t solarValue1 = adcSolarSensor.read(solarPin1) ;
	uint16_t solarValue2 = adcSolarSensor.read(solarPin2);
	uint16_t solarValue3 = adcSolarSensor.read(solarPin3);
	uint16_t solarValue4 = adcSolarSensor.read(solarPin4);
	for(int i = 0; i < SSReadNum-1; i++){
		solarValue1 += adcSolarSensor.read(solarPin1) ;
		solarValue2 += adcSolarSensor.read(solarPin2) ;
		solarValue3 += adcSolarSensor.read(solarPin3) ;
		solarValue4 += adcSolarSensor.read(solarPin4) ;
	}

	if(is_callibratingSS){
		latestSunSensorData[0] = solarValue1*ADCMULT;
		latestSunSensorData[1] =  solarValue2*ADCMULT;
		latestSunSensorData[2] = solarValue3*ADCMULT;
		latestSunSensorData[3] = solarValue4*ADCMULT;
	}
	else{
		latestSunSensorData[0] = (solarValue1*ADCMULT-calibDataSS.xMin)/(calibDataSS.xMax-calibDataSS.xMin);
		latestSunSensorData[1] =  (solarValue2*ADCMULT-calibDataSS.yMin)/(calibDataSS.yMax-calibDataSS.yMin);
		latestSunSensorData[2] =  (solarValue3*ADCMULT-calibDataSS.zMin)/(calibDataSS.zMax-calibDataSS.zMin);
		latestSunSensorData[3] =  (solarValue4*ADCMULT-calibDataSS.qMin)/(calibDataSS.qMax-calibDataSS.qMin);
		 
	}
	float ang = float(180/M_PI)*atan2(latestSunSensorData[2]-latestSunSensorData[0], latestSunSensorData[3]-latestSunSensorData[1])+ss0offsetAngle;
	latestSSAngleValue = ang;
	if(ang > 180) latestSSAngleValue= -360+ang;
	else if(ang < -180) latestSSAngleValue = 360+ang;
	//latestSunSensorData[0] = latestSunSensorData[2]-latestSunSensorData[0];
	//latestSunSensorData[1] = latestSunSensorData[3]-latestSunSensorData[1];
	sunPositionTopic.publish({latestSSAngleValue, ss0offsetAngle});
}

void SensorCollector::collectPowerMeter(){
	float solarVolt= adcPower.read(panelVoltPin) / ADCRes * ADCRef;
	float solarAmp = adcPower.read(panelAmpPin) / ADCRes * ADCRef;
	float motorAmp = adcPower.read(motorAmpPin) / ADCRes * ADCRef;
	latestPowerData = {solarVolt, solarAmp, motorAmp};
}

void SensorCollector::runSensorCollectorThread() {
	int64_t now = RODOS::NOW();
	
	if(IMUOnOff &&  now - lastRunIMU > intervalIMU){
		collectIMU();
		lastRunIMU = now;
		if(is_calibratingMagn){
			if(now - calibStartedMagnAt > CALIB_TIME*RODOS::SECONDS) {
				is_calibratingMagn = false;
				PRINTF("Magn CALLIB ENDED\n VALUES: {%f, %f, %f, %f, %f, %f}\n", (double) calibDataMagn.xMin, (double) calibDataMagn.xMax, (double) calibDataMagn.yMin, (double) calibDataMagn.yMax, (double) calibDataMagn.zMin, (double) calibDataMagn.zMax);

			}
			if(latestIMUData.magnetometer[0]>calibDataMagn.xMax) calibDataMagn.xMax = latestIMUData.magnetometer[0];
			else if(latestIMUData.magnetometer[0]<calibDataMagn.xMin) calibDataMagn.xMin = latestIMUData.magnetometer[0];

			if(latestIMUData.magnetometer[1]>calibDataMagn.yMax) calibDataMagn.yMax = latestIMUData.magnetometer[1];
			else if(latestIMUData.magnetometer[1]<calibDataMagn.yMin) calibDataMagn.yMin = latestIMUData.magnetometer[1];

			if(latestIMUData.magnetometer[2]>calibDataMagn.zMax) calibDataMagn.zMax = latestIMUData.magnetometer[2];
			else if(latestIMUData.magnetometer[2]<calibDataMagn.zMin) calibDataMagn.zMin = latestIMUData.magnetometer[2];
		}

		if(calib_gyro){
			for(int i = 0; i < 3; ++i) calib_gyro_sums[i] += GYR_REAL_VALS[i];

			calib_gyro_counter++;

			if(calib_gyro_counter >= 500){
				calib_gyro = false;
				for(int i = 0; i < 3; ++i) GYR_CALIB_VALS[i] = calib_gyro_sums[i] / float(calib_gyro_counter);
				
				RODOS::PRINTF("CALIB GYRO DONE\n");
			}
		}
	}
	if(SunSensorsOnOff && now - lastRunSunSensors > intervalSunSensors){
		collectSunSensors();
		lastRunSunSensors = now;
		if(is_callibratingSS){
			if(now - calibSSStartedAt > CALIB_TIME*RODOS::SECONDS) {
				is_callibratingSS = false;
				PRINTF("SS CALLIB ENDED\n VALUES: {%f, %f, %f, %f, %f, %f, %f, %f}\n", (double) calibDataSS.xMin, (double) calibDataSS.xMax, (double) calibDataSS.yMin, (double) calibDataSS.yMax, (double) calibDataSS.zMin, (double) calibDataSS.zMax, (double) calibDataSS.qMin, (double) calibDataSS.qMax);
			}
			if(latestSunSensorData[0]>calibDataSS.xMax) calibDataSS.xMax = latestSunSensorData[0];
			else if(latestSunSensorData[0]<calibDataSS.xMin) calibDataSS.xMin = latestSunSensorData[0];

			if(latestSunSensorData[1]>calibDataSS.yMax) calibDataSS.yMax = latestSunSensorData[1];
			else if(latestSunSensorData[1]<calibDataSS.yMin) calibDataSS.yMin = latestSunSensorData[1];

			if(latestSunSensorData[2]>calibDataSS.zMax) calibDataSS.zMax = latestSunSensorData[2];
			else if(latestSunSensorData[2]<calibDataSS.zMin) calibDataSS.zMin = latestSunSensorData[2];

			if(latestSunSensorData[3]>calibDataSS.qMax) calibDataSS.qMax = latestSunSensorData[3];
			else if(latestSunSensorData[3]<calibDataSS.qMin) calibDataSS.qMin = latestSunSensorData[3];
		}
		else if(is_callibratingSS0Offset){
			if(now - callibSS0OffsetStartedAt> 3*RODOS::SECONDS) {
				is_callibratingSS0Offset = false;
				ss0offsetAngle=-ss0offsetAngleSum/float(ss0offsetCounter);
			}
			ss0offsetAngleSum+=latestSSAngleValue;
			ss0offsetCounter++;
		}
		//PRINTF("ANG: %f\n",atan2(latestSunSensorData[2]-latestSunSensorData[0], latestSunSensorData[3]-latestSunSensorData[1]));
	}
	if(now - lastRunPowerMeter > intervalPowerMeter){
		collectPowerMeter();
		lastRunPowerMeter = now;
	}

	if(currentMode.mode == 9){
		if(currentMode.submode == 0 && !is_callibratingSS && !is_calibratingMagn){
			SensorCollector::currentMode.submode = 1;
			generated::modeTopic.publish(SensorCollector::currentMode);
		}
		else if(currentMode.submode == 3 && !is_callibratingSS0Offset){
			SensorCollector::currentMode.submode = 4;
			sunPositionTopic.publish({latestSSAngleValue, ss0offsetAngle});
			generated::modeTopic.publish(SensorCollector::currentMode);
		}
	}

	auto stdTM = this->standardTelemetry.access();
	stdTM->sunAngle = latestSSAngleValue;
	stdTM->magnetoRawAngle = atan2(latestIMUData.magnetometer[0], latestIMUData.magnetometer[1]);
}


//Telecommand methods
bool SensorCollector::handleTelecommandNOP() {
	PRINTF("SENSORCOLLECTOR -> NOP\n");
	return true;
}

bool SensorCollector::handleTelecommandSetCollectionInterval(const generated::SetCollectionInterval &setCollectionInterval) {
	PRINTF("SENSORCOLLECTOR -> SET INTERVALS\n");
	
	switch(setCollectionInterval.sensor){
		case 0:
			intervalIMU = setCollectionInterval.interval*RODOS::MILLISECONDS;
			break;
		case 1:
			intervalSunSensors = setCollectionInterval.interval*RODOS::MILLISECONDS;
			break;
		case 2:
			intervalPowerMeter = setCollectionInterval.interval*RODOS::MILLISECONDS;
			break;
		default:
			RODOS::PRINTF("INVALID SENSOR SET COLLECTION INTERVALL");
			break;
	}

	return true;
}

bool SensorCollector::handleTelecommandSendCollectionIntervals() {
	PRINTF("SENSORCOLLECTOR -> SEND INTERVALS\n");
	
	collectionIntervals_tm.intervals[0] = intervalIMU;
	collectionIntervals_tm.intervals[1] = intervalSunSensors;
	collectionIntervals_tm.intervals[2] = intervalPowerMeter;
	telemetry = finalizeTelemetry(collectionIntervals_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);

	return true;
}

bool SensorCollector::handleTelecommandCallibMagnetometer(){
	PRINTF("SENSORCOLLECTOR -> CALLIB MAGNETO\n");

	is_calibratingMagn = true;
	calibDataMagn = {FLT_MAX, -FLT_MAX, FLT_MAX, -FLT_MAX, FLT_MAX, -FLT_MAX};
	calibStartedMagnAt = RODOS::NOW();

	return true;
}

bool SensorCollector::handleTelecommandCallibSS(){
	PRINTF("SENSORCOLLECTOR -> CALLIB SS\n");

	calibSSStartedAt = RODOS::NOW();
	is_callibratingSS = true;
	calibDataSS = {FLT_MAX, -FLT_MAX, FLT_MAX, -FLT_MAX, FLT_MAX, -FLT_MAX, FLT_MAX, -FLT_MAX};

	return true;
}

bool SensorCollector::handleTelecommandCallibSS0Offset(){
	RODOS::PRINTF("SENSORCOLLECTOR -> CALLIB SS OFFSET\n");

	callibSS0OffsetStartedAt = RODOS::NOW();
	is_callibratingSS0Offset = true;
	ss0offsetAngle = 0.0f;
	ss0offsetCounter = 0;
	ss0offsetAngleSum = 0.0f;

	return true;
}

bool SensorCollector::handleTelecommandCallibGyro() {
	RODOS::PRINTF("SENSORCOLLECTOR -> CALLIB GYRO\n");

	for(int i = 0; i < 3; ++i) GYR_CALIB_VALS[i] = 0.0f;
	for(int i = 0; i < 3; ++i) calib_gyro_sums[i] = 0.0f;

	calib_gyro = true;
	calib_gyro_counter = 0;

	return true;
}

bool SensorCollector::handleTelecommandSendCallibValues() {
	RODOS::PRINTF("SENSORCOLLECTOR -> SEND CALLIB VALUES\n");

	for(int i = 0; i < 3; ++i) calibrationValues_tm.acc[i] = ACC_CALIB_VALS[i];
	for(int i = 0; i < 3; ++i) calibrationValues_tm.gyr[i] = GYR_CALIB_VALS[i];
	
	calibrationValues_tm.mag[0] = calibDataMagn.xMax;
	calibrationValues_tm.mag[1] = calibDataMagn.xMin;
	calibrationValues_tm.mag[2] = calibDataMagn.yMax;
	calibrationValues_tm.mag[3] = calibDataMagn.yMin;
	calibrationValues_tm.mag[4] = calibDataMagn.zMax;
	calibrationValues_tm.mag[5] = calibDataMagn.zMin;

	calibrationValues_tm.solarSens[0] = calibDataSS.qMax;
	calibrationValues_tm.solarSens[1] = calibDataSS.qMin;
	calibrationValues_tm.solarSens[2] = calibDataSS.xMax;
	calibrationValues_tm.solarSens[3] = calibDataSS.xMin;
	calibrationValues_tm.solarSens[4] = calibDataSS.yMax;
	calibrationValues_tm.solarSens[5] = calibDataSS.yMin;
	calibrationValues_tm.solarSens[6] = calibDataSS.zMax;
	calibrationValues_tm.solarSens[7] = calibDataSS.zMin;

	calibrationValues_tm.ssOffset = ss0offsetAngle;

	telemetry = finalizeTelemetry(calibrationValues_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);

	return true;
}

//Topic methods
void SensorCollector::handleTopicModeTopic(generated::ModeTopic &message){
	SensorCollector::currentMode = message;
	if(currentMode.mode == 9){
		if(currentMode.submode == 0){
			handleTelecommandCallibSS();
			handleTelecommandCallibMagnetometer();
		}
		else if(currentMode.submode == 3){
			handleTelecommandCallibSS0Offset();
		}
	}
}

void SensorCollector::handleTopicPeripheralOnOffTopic(generated::PeripheralOnOffTopic &message){
	if(!IMUOnOff && message.state.getBit(0)){
		initIMU();
	}
	IMUOnOff = message.state.getBit(0);

	SunSensorsOnOff = message.state.getBit(1);
	PRINTF("SS: %d\n", SunSensorsOnOff);
}

void SensorCollector::initSensorExtTelemetryThread(){}

void SensorCollector::runSensorExtTelemetryThread(){
	sensorData_tm.acc[0] = latestIMUData.accelerometer[0];
	sensorData_tm.acc[1] = latestIMUData.accelerometer[1];
	sensorData_tm.acc[2] = latestIMUData.accelerometer[2];

	sensorData_tm.gyr[0] = latestIMUData.gyroscope[0];
	sensorData_tm.gyr[1] = latestIMUData.gyroscope[1];
	sensorData_tm.gyr[2] = latestIMUData.gyroscope[2];

	sensorData_tm.mag[0] = latestIMUData.magnetometer[0];
	sensorData_tm.mag[1] = latestIMUData.magnetometer[1];
	sensorData_tm.mag[2] = latestIMUData.magnetometer[2];

	sensorData_tm.solarSens[0] = latestSunSensorData[0];
	sensorData_tm.solarSens[1] = latestSunSensorData[1];//-latestSunSensorData[0];
	sensorData_tm.solarSens[2] = latestSunSensorData[2];
	sensorData_tm.solarSens[3] = latestSunSensorData[3];
	sensorData_tm.solarSensXDiff = latestSunSensorData[3]-latestSunSensorData[1];
	sensorData_tm.solarSensYDiff = latestSunSensorData[2]-latestSunSensorData[0];

	sensorData_tm.solar_volts = latestPowerData.volts;

	telemetry = finalizeTelemetry(sensorData_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);
}
