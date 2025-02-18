// generated using CreateApp.sh

#include "sensors.h"

#include "hal/hal_adc.h"

// LIDAR
#include "MedianFilter.h"
#include "VL53L4ED_api.h"

#include "rodos.h"

#define TOF_I2C_ADDRESS 0x29

// IMU init values 
#define IMU_I2C_IDX RODOS::I2C_IDX::I2C_IDX2                       //PB10 & PB11
int16_t GYR_CALIB_VALS[3] = {131,30,-14};                          // offset
int16_t ACC_CALIB_VALS[3] = {228,0,0};                             // offset
int16_t MAG_BOUNDRIES[3][2] = {{863,1289},{-955,-415},{-168,-42}}; //{x[min,max], y[min,max], z[min,max]}

int16_t NEW_MAG_BOUNDRIES[3][2] = {{-285 ,617},{423,1345},{-1194 ,-1087}}; //buffer if we want to calib the mag


Sensors::Sensors():imu(IMU_I2C_IDX){}//,GYR_CALIB_VALS,ACC_CALIB_VALS,MAG_BOUNDRIES){} 

/**
 * @brief Sun Sensor adc
 * some defines and functions, so our run method isn't 300 lines of code
 */
#define ADC_NUM_ITERATIONS 5                   // averages across 5 adc readings
#define SUN_PIN RODOS::ADC_CHANNEL::ADC_CH_004 // PA4
#define ADC_BITS 12
#define ADC_RESOLUTION float((1 << (ADC_BITS - 1)) - 1) // 2 ^ ADC_BITS - 1
RODOS::HAL_ADC adc(RODOS::ADC_IDX::ADC_IDX1);

float SUN_BOUND[2] = {0, 3600}; // it works I guess

void Sensors::readSunSensor()
{
    u_int16_t acc = 0;
    for (int i = 0; i < ADC_NUM_ITERATIONS; i++)
        acc += adc.read(SUN_PIN);
    auto SUN_RAW_VAL = acc / ADC_NUM_ITERATIONS;

    lightSensorBuffer.intensity = (SUN_RAW_VAL - SUN_BOUND[0]) / float(SUN_BOUND[1] - SUN_BOUND[0]);
}

int iteration = 0;

void Sensors::initialize()
{
}

// true enables median filter
bool tof_filter_flag = true;
static MedianFilter<int, 25> filter;

// everything regarding LIDAR is basically TAMARIW code

void init_lidar()
  {
    tof_i2c_init();
    PRINTF("initializing...\n");
    // Initialize and return status
    if (VL53L4ED_SensorInit(TOF_I2C_ADDRESS) == VL53L4ED_ERROR_NONE)
    {
      // Enable 10 ms sampling and start sampling
      VL53L4ED_SetRangeTiming(TOF_I2C_ADDRESS, 10, 0);
      VL53L4ED_StartRanging(TOF_I2C_ADDRESS);
      PRINTF("\r\nToF initialized!\r\n");
    }
    else
    {
      PRINTF("\r\nToF error!\r\n");
    }
  }

// Thread methods
void Sensors::initCollectData()
{

    // init IMU and the registers required to read i2c
    imu.init(400000);

    // init adc for solar sensor
    adc.config(RODOS::ADC_PARAMETER_TYPE::ADC_PARAMETER_RESOLUTION, ADC_BITS);
    adc.init(SUN_PIN);
    
    time=RODOS::NOW();
    // init LIDAR
    
}

void Sensors::readLIDAR()
{
    uint8_t data_ready = 0;
    int distance_raw = 0;

    VL53L4ED_ResultsData_t tof_result;

    // Wait for data to be ready
    if (data_ready != (uint8_t)1)
    {
        AT(NOW() + 2 * MILLISECONDS);
        VL53L4ED_CheckForDataReady(TOF_I2C_ADDRESS, &data_ready);
        
    }

    // Read distance measurements
    if (VL53L4ED_GetResult(TOF_I2C_ADDRESS, &tof_result) == VL53L4ED_ERROR_NONE)
    {   
        
        if (tof_filter_flag)
        {
            filter.addSample(tof_result.distance_mm);
            distance_raw = filter.getMedian();
        }
        else
        {
            distance_raw = tof_result.distance_mm;
        }
        VL53L4ED_ClearInterrupt(TOF_I2C_ADDRESS);

    }
    else
    {   
        init_lidar();
    }
    float distance = (((-1.272089e-10*distance_raw+0.00000047833609)*distance_raw-0.0003512875)*distance_raw+0.12808240463)*distance_raw-0.94115216068;
    proximityBuffer.distance = distance;
}

void Sensors::handleTopicCalibMagTopic(generated::CalibMagTopic &message){
    calibMagBuffer = message;
    if(calibMagBuffer.is_calibrating){
        // start calibration
        for (int i = 0; i < 3; i++)
        {
            NEW_MAG_BOUNDRIES[i][0] = INT16_MAX;
            NEW_MAG_BOUNDRIES[i][1] = INT16_MIN;
        }
    }
    else{
        // end calibration
        for(int i = 0;i<3;i++){
            MAG_BOUNDRIES[i][0] = NEW_MAG_BOUNDRIES[i][0];
            MAG_BOUNDRIES[i][1] = NEW_MAG_BOUNDRIES[i][1];
            imu.MAG_BOUNDRIES[i][0] = NEW_MAG_BOUNDRIES[i][0];
            imu.MAG_BOUNDRIES[i][1] = NEW_MAG_BOUNDRIES[i][1];
        }
    }

}

void Sensors::read_IMU(){

    //read IMU
    imu.read_adj();
    //imu.print_real();
    imu.cpy_adj(imuTopicBuffer.accelerometer, imuTopicBuffer.gyroscope, imuTopicBuffer.magnetometer);

    //if calib, read raw and update calib values
    if(calibMagBuffer.is_calibrating){
        imu.read_raw();
        for (int i = 0; i < 3; i++)
        {
            NEW_MAG_BOUNDRIES[i][0] = min(imu.MAG_RAW_VALS[i], NEW_MAG_BOUNDRIES[i][0]);
            NEW_MAG_BOUNDRIES[i][1] = max(imu.MAG_RAW_VALS[i], NEW_MAG_BOUNDRIES[i][1]);
        }
    }
}

void Sensors::runCollectData()
{
    if(iteration==0){
        init_lidar();
        imu.init(400000);
    }
    iteration++;
    
    // read and pulish IMU
    read_IMU();
    imuDataTopic.publish(imuTopicBuffer);

    // read and publish Sun sensor (Photoresistor)
    readSunSensor();
    lightSensorTopic.publish(lightSensorBuffer);

    // read and publish LIDAR (ToF distance)
    readLIDAR();
    proximityTopic.publish(proximityBuffer);
    publishTM();
}

// Telecommand methods
bool Sensors::handleTelecommandNOP()
{
    return false;
}

bool Sensors::handleTelecommandCalibGyro()
{
    PRINTF("doing the calibrating...\n");
    AT(NOW() + 2 * SECONDS);
    PRINTF("nah just kidding\n");
    return false;
}

void Sensors::publishTM()
{   
    if(RODOS::NOW() - time > 1 * RODOS::SECONDS){
        time=RODOS::NOW();
        corfu::Accessor stdtm = this->standardTelemetry.access();
        stdtm->roll = imuTopicBuffer.gyroscope[0];
        stdtm->pitch = imuTopicBuffer.gyroscope[1];
        stdtm->yaw = imuTopicBuffer.gyroscope[2];
        stdtm->ax = imuTopicBuffer.accelerometer[0];
        stdtm->ay = imuTopicBuffer.accelerometer[1];
        stdtm->az = imuTopicBuffer.accelerometer[2];
        stdtm->mx = imuTopicBuffer.magnetometer[0];
        stdtm->my = imuTopicBuffer.magnetometer[1];
        stdtm->mz = imuTopicBuffer.magnetometer[2];
        stdtm->distance = float(proximityBuffer.distance);
        stdtm->brightness = lightSensorBuffer.intensity;
        stdtm->magx0 = MAG_BOUNDRIES[0][0]; 
        stdtm->magx1 = MAG_BOUNDRIES[0][1]; 
        stdtm->magy0 = MAG_BOUNDRIES[1][0]; 
        stdtm->magy1 = MAG_BOUNDRIES[1][1]; 
        stdtm->magz0 = MAG_BOUNDRIES[2][0]; 
        stdtm->magz1 = MAG_BOUNDRIES[2][1]; 
    }
}