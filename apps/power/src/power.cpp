// generated using CreateApp.sh

#include "power.h"
#include "hal/hal_adc.h"
#include "hal/hal_gpio.h"
#include "rodos.h"
/**
 * @brief adcs
 * one adc hal object to read different pins
 */
#define ADC_BITS 12
#define ADC_RESOLUTION float((1 << ADC_BITS) - 1)  // 2 ^ ADC_BITS - 1
RODOS::HAL_ADC adcPower(RODOS::ADC_IDX::ADC_IDX1); // why does this work? its not defined for stm??

#define CURRENT_PIN RODOS::ADC_CHANNEL::ADC_CH_006 // PA6
#define CURRENT_ITERATIONS 5
#define C_SMALL_R 10000
#define C_BIG_R 1

#define VOLTAGE_PIN RODOS::ADC_CHANNEL::ADC_CH_000 // PA0
#define VOLTAGE_ITERATIONS 5
#define V_SMALL_R 1490 // Kleiner widerstand in Kiloohm ( v drop wird hier gemessen)
#define V_BIG_R 8230   // Großer widerstand in Kiloohm (In reihe zu V_SMALL_R, damit 3V nicht überschritten wird)
#define I_P 5		   // Max Current (name copied from the datasheet .-.)
#define U_MAX 1.5	   // 0.5 for I_P = 20V and I_P = 30V
#define U_MIN 3.5	   // 4.5 for I_P = 20V and I_P = 30V

/**
 * @brief GPIO
 * once the voltage drops below 5V, this GPIO is set active to light an LED
 */
#define LED_PIN RODOS::GPIO_079	   // PE15
RODOS::HAL_GPIO led_gpio(LED_PIN); // PC6 pin

float voltage = 0.0f;
float current = 0.0f;

void Power::initialize()
{
}

// Thread methods
void Power::initMainthread()
{
	adcPower.config(RODOS::ADC_PARAMETER_TYPE::ADC_PARAMETER_RESOLUTION, ADC_BITS);
	adcPower.init(CURRENT_PIN);
	adcPower.init(VOLTAGE_PIN);
	time=RODOS::NOW();
	led_gpio.init(1, 1, 0);
}

void Power::runMainthread()
{
	readVoltage();
	readCurrent();
	powerTopic.publish(powerTopicBuffer);
	update_led();
	
	updateStdTM();
}

void Power::readVoltage()
{
	uint16_t acc = 0;
	for (int i = 0; i < VOLTAGE_ITERATIONS; i++)
		acc += adcPower.read(VOLTAGE_PIN);
	float v_raw = acc / (VOLTAGE_ITERATIONS * ADC_RESOLUTION) * 3.0f;
	voltage = v_raw * float(V_SMALL_R + V_BIG_R) / float(V_SMALL_R);
	// PRINTF("V: %f\n", double(voltage));
	powerTopicBuffer.voltage = voltage;
}

void Power::readCurrent()
{
	uint16_t acc = 0;
	for (int i = 0; i < CURRENT_ITERATIONS; i++)
		acc += adcPower.read(CURRENT_PIN);
	float c_v_raw = acc / (CURRENT_ITERATIONS * ADC_RESOLUTION) * 3.0f;
	float c_voltage = c_v_raw * float(C_SMALL_R + C_BIG_R) / float(C_SMALL_R);
	current = (c_voltage - 2.571f) * I_P / -3.56f;
	//PRINTF("c_v: %f\n", double(c_voltage));
	//PRINTF("I: %f\n", double(current));
	powerTopicBuffer.current = current;
}

void Power::update_led()
{
	if (voltage < 11.84f)
		led_gpio.setPins(true);
}

void Power::updateStdTM(){
	if(RODOS::NOW() - time > 1 * RODOS::SECONDS){
        time=RODOS::NOW();
		auto stdTM = this->standardTelemetry.access();
		stdTM->voltage = voltage;
		stdTM->current = current;
		//PRINTF("V: %f\n", double(voltage));
		//PRINTF("I: %f\n", double(current));
	}
}

// Telecommand methods
bool Power::handleTelecommandNOP()
{
	return false;
}