// generated using CreateApp.sh

#include "sensors.h"

#include "hal/hal_adc.h"

// LIDAR
#include "MedianFilter.h"
#include "VL53L4ED_api.h"

#define TOF_I2C_ADDRESS 0x29

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
        while (1)
        {
        }
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

    // init LIDAR
    init_lidar();
}

void Sensors::readLIDAR()
{
    uint8_t data_ready = 0;
    int distance = 0;

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
            distance = filter.getMedian();
        }
        else
        {
            distance = tof_result.distance_mm;
        }
        VL53L4ED_ClearInterrupt(TOF_I2C_ADDRESS);
    }
    else
    {
        PRINTF("ToF ranging error!\n");
    }
    proximityBuffer.distance = distance;
}

void Sensors::runCollectData()
{
    iteration++;

    // read and pulish IMU
    imu.read_adj();
    imu.cpy_adj(imuTopicBuffer.accelerometer, imuTopicBuffer.gyroscope, imuTopicBuffer.magnetometer);
    imuDataTopic.publish(imuTopicBuffer);

    // read and publish Sun sensor (Photoresistor)
    readSunSensor();
    lightSensorTopic.publish(lightSensorBuffer);

    // read and publish LIDAR (ToF distance)
    readLIDAR();
    proximityTopic.publish(proximityBuffer);
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