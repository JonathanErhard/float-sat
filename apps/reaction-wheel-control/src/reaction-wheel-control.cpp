//generated using CreateApp.sh

// Author: Konstantin Winkel

#include "../include/reaction-wheel-control.h" 

#include "rodos.h"
#include "hal_pwm.h"
#include "hal_gpio.h"

#define PWM_FREQ 5000
#define PWM_INC 1000
#define PWM_MAX_DELTA 100

HAL_PWM motor_pwm_1(RODOS::PWM_IDX::PWM_IDX14);
HAL_PWM motor_pwm_2(RODOS::PWM_IDX::PWM_IDX15);

#define SATURATION_VALUE 100
#define MAX_ERROR_SUM 500

//coppied from Senors.cpp written by Atheel Redah @ University of Würzburg, January 20, 2019
__IO uint32_t IC4ReadValue1 = 0, IC4ReadValue2 = 0, Capture = 0;
__IO uint8_t CaptureNumber = 0;
__IO uint32_t TIM2Freq = 0;
__IO uint8_t EncoderB;
__IO int64_t CaptureTime;
HAL_GPIO missed_val(RODOS::GPIO_PIN::GPIO_061);
void ReactionWheelControl::initialize(){
  missed_val.init(1,1,0);
  for(int i = 0; i < ReactionWheelControl::reader_buffer.getLen(); ++i){
    ReactionWheelControl::reader_buffer.vals[i] = 0;
  }
}


//Thread methods
void ReactionWheelControl::initReactionWheelControlThread() {
	EncoderInit();
  ReactionWheelControl::reactioncontrol_alive = corfu::Alive(appId, RODOS::NOW() + 5*RODOS::SECONDS);

  motor_pwm_1.init(PWM_FREQ, PWM_INC);
  motor_pwm_2.init(PWM_FREQ, PWM_INC);
}

void ReactionWheelControl::runReactionWheelControlThread() {
  if(RODOS::NOW()<5*RODOS::SECONDS) return;
  
  ReactionWheelControl::iterator++;

	MotorSpeedUpdate();

  biasOffsetTopic.publish({ReactionWheelControl::rotation_speed});

  float err =  ReactionWheelControl::desired_speed - ReactionWheelControl::rotation_speed;
  //if(err > 200.0f) err = 200.0f;
 // if(err < -200.0f) err = -200.0f;

  ReactionWheelControl::error=err;

  ReactionWheelControl::error_sum += ReactionWheelControl::error * 10.0f/1000.0f;

  ReactionWheelControl::control_output = ReactionWheelControl::PI_values[0] * ReactionWheelControl::error + ReactionWheelControl::PI_values[1] * ReactionWheelControl::error_sum;

  ReactionWheelControl::prev_pwm = ReactionWheelControl::current_pwm;
  ReactionWheelControl::current_pwm = ReactionWheelControl::control_output;

  float pwm_delta = ReactionWheelControl::current_pwm - ReactionWheelControl::prev_pwm;
  if(pwm_delta > PWM_MAX_DELTA)
    ReactionWheelControl::current_pwm = ReactionWheelControl::prev_pwm+PWM_MAX_DELTA;
  
  else if(pwm_delta < -PWM_MAX_DELTA)
    ReactionWheelControl::current_pwm = ReactionWheelControl::prev_pwm-PWM_MAX_DELTA;

  if(ReactionWheelControl::current_pwm > PWM_INC) ReactionWheelControl::current_pwm = PWM_INC;
  if(ReactionWheelControl::current_pwm < -PWM_INC) ReactionWheelControl::current_pwm = -PWM_INC;

  //output_buffer.put(ReactionWheelControl::current_pwm);
  //float sum = 0;
  //for(int i = 0; i < 10; ++i) sum += output_buffer.vals[i];
  //sum /= 10.0f;

  //ReactionWheelControl::current_int_pwm = static_cast<int32_t>(sum);
  ReactionWheelControl::current_int_pwm = static_cast<int32_t>(ReactionWheelControl::current_pwm);

  if(ReactionWheelControl::desired_speed == 0) {
    ReactionWheelControl::current_int_pwm = 0;
    ReactionWheelControl::error_sum = 0.0f;
  }

  if(ReactionWheelControl::current_int_pwm >= 0) {
    motor_pwm_1.write((uint32_t) ReactionWheelControl::current_int_pwm);
    motor_pwm_2.write(0);
  }
  else{
    motor_pwm_1.write(0);
    motor_pwm_2.write((uint32_t) abs(ReactionWheelControl::current_int_pwm));
  }


  if(ReactionWheelControl::iterator > 10){
    ReactionWheelControl::iterator = 0;
    ReactionWheelControl::reactioncontrol_alive.timeout = RODOS::NOW() + 5*RODOS::SECONDS;
	  corfuAppIsAliveTopic.publish(ReactionWheelControl::reactioncontrol_alive);
    updateStdTM();
  }

}


//Telecommand methods

bool ReactionWheelControl::handleTelecommandNOP() {
	RODOS::PRINTF("REACTIONCONTROL -> NOP\n");
	return true;
}

bool ReactionWheelControl::handleTelecommandSetPIControlValueWheel(const generated::SetPIControlValueWheel &setPIControlValue) {
	RODOS::PRINTF("REACTIONCONTROL -> SetPIControlValue { %d %f }\n", setPIControlValue.identifier, (double) setPIControlValue.value);

	if(setPIControlValue.identifier > 1) return false;

	ReactionWheelControl::PI_values[setPIControlValue.identifier] = setPIControlValue.value;

  ReactionWheelControl::error_sum = 0; //Safety because wierd things can happen

	return true;
}

bool ReactionWheelControl::handleTelecommandSendPIControlValues() {
	RODOS::PRINTF("REACTIONCONTROL -> SendPIControlValues\n");

	corfu::Telemetry telemetry;

	pIValuesWheel_tm.P_Value = ReactionWheelControl::PI_values[0];
	pIValuesWheel_tm.I_Value = ReactionWheelControl::PI_values[1];

	telemetry = finalizeTelemetry(pIValuesWheel_tm);
	corfu::extendedTelemetryTopic.publish(telemetry);

	return true;
}

bool ReactionWheelControl::handleTelecommandSetDesiredSpeed(const generated::SetDesiredSpeed &setDesiredSpeed) {
  RODOS::PRINTF("REACTIONCONTROL -> SetDesiredSpeed { %f }\n", (double) setDesiredSpeed.speed);
  ReactionWheelControl::desired_speed = setDesiredSpeed.speed;
  return true;
}

//Topic methods
void ReactionWheelControl::handleTopicDesiredMotorSpeedTopic(generated::DesiredMotorSpeedTopic &message){
  ReactionWheelControl::desired_speed = message.speed;
}

void ReactionWheelControl::handleTopicAttitudeDeterminationTopic(generated::AttitudeDeterminationTopic &message){
  atd = message;
}

//Methods coppied from Sensors.cpp written by Atheel Redah @ University of Würzburg, January 20, 2019

void ReactionWheelControl::EncoderInit()
{
  GPIO_InitTypeDef GPIO_InitStructure;
  NVIC_InitTypeDef NVIC_InitStructure;
  TIM_ICInitTypeDef  TIM_ICInitStructure;

  /* TIM2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);

  /* GPIOA clock enable */
  RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

  /* TIM2 channel 4 pin (PA3) configuration for Encoder A (Yellow)*/
  GPIO_InitStructure.GPIO_Pin =  GPIO_Pin_3;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* Connect TIM pins to AF2 */
  GPIO_PinAFConfig(GPIOA, GPIO_PinSource3, GPIO_AF_TIM2);

  /* Configure (PA5) pin as input floating for Encoder B (White)*/
  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_5;
  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
  GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
  GPIO_Init(GPIOA, &GPIO_InitStructure);

  /* -----------------------------------------------------------------------
     TIM2 Configuration:

     In this example TIM2 input clock (TIM2CLK) is set to 2 * APB1 clock (PCLK1):
     	 TIM2CLK = SystemCoreClock / 2 = 84000000 Hz

     To get TIM2 counter clock at X Hz, the prescaler is computed as follows:
     	 Prescaler = (TIM3CLK / TIM3 counter clock) - 1
     	 Prescaler = ((SystemCoreClock /2) / X Hz) - 1

     Note:
     SystemCoreClock variable holds HCLK frequency and is defined in system_stm32f4xx.c file.
    ----------------------------------------------------------------------- */
  //TIM_PrescalerConfig(TIM2, (uint16_t) (((SystemCoreClock/2) / X) - 1), TIM_PSCReloadMode_Immediate);

  /* Enable the TIM2 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);

  /* TIM2 configuration: Input Capture mode ---------------------
     The external signal is connected to TIM2 CH4 pin (PA3)
     The Rising edge is used as active edge,
     The TIM2 CCR4 is used to compute the frequency value
  ------------------------------------------------------------ */
  TIM_ICInitStructure.TIM_Channel = TIM_Channel_4;
  TIM_ICInitStructure.TIM_ICPolarity = TIM_ICPolarity_Rising;
  TIM_ICInitStructure.TIM_ICSelection = TIM_ICSelection_DirectTI;
  TIM_ICInitStructure.TIM_ICPrescaler = TIM_ICPSC_DIV8;		/*!< Capture performed once every 8 events. */
  TIM_ICInitStructure.TIM_ICFilter = 0x0;

  TIM_ICInit(TIM2, &TIM_ICInitStructure);

  /* TIM enable counter */
  TIM_Cmd(TIM2, ENABLE);

  /* Enable the CC2 Interrupt Request */
  TIM_ITConfig(TIM2, TIM_IT_CC4, ENABLE);
}

extern "C" {
/**
  * @brief  This function handles TIM2 global interrupt request.
  * @param  None
  * @retval None
  */
  void TIM2_IRQHandler(void)
  {
    if(TIM_GetITStatus(TIM2, TIM_IT_CC4) == SET)
    {
      /* Clear TIM2 Capture compare interrupt pending bit */
      TIM_ClearITPendingBit(TIM2, TIM_IT_CC4);
      CaptureTime = RODOS::NOW();
      if(CaptureNumber == 0)
      {
        /* Get the Input Capture value */
        IC4ReadValue1 = TIM_GetCapture4(TIM2);
        CaptureNumber = 1;
      }
      else if(CaptureNumber == 1)
      {
        EncoderB = GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_5);
        /* Get the Input Capture value */
        IC4ReadValue2 = TIM_GetCapture4(TIM2);

        /* Capture computation */
        if (IC4ReadValue2 > IC4ReadValue1) Capture = (IC4ReadValue2 - IC4ReadValue1);
        else if (IC4ReadValue2 < IC4ReadValue1) Capture = ((0xFFFFFFFF - IC4ReadValue1) + IC4ReadValue2);

        /* Frequency computation */
        TIM2Freq = (uint32_t) ((SystemCoreClock/2)) * 8 / Capture;
        CaptureNumber = 0;
      }
    }
  }
}

void ReactionWheelControl::MotorSpeedUpdate() {
	double SensorTime = (double)(RODOS::NOW()-CaptureTime)/(double)RODOS::MILLISECONDS;
  //minimum measured speed is 2 RPS(120 RPM). This can give us 250ms of minimum interval between interrupts (2 interrupts every one revolution).
	if (SensorTime>250) TIM2Freq=0;

  float temp_speed = 0;

	if (EncoderB) temp_speed  = -1*((float)TIM2Freq / 16) * 60;  //CCW
	else temp_speed  = ((float)TIM2Freq / 16) * 60; //CW

  if(true){
    ReactionWheelControl::reader_buffer.put(temp_speed);

    //Median filter
    
    memcpy(values,ReactionWheelControl::reader_buffer.vals, sizeof(values));


    float temp;
    for(int j = 0; j < ReactionWheelControl::reader_buffer.getLen(); ++j){
      for(int i = 0; i < ReactionWheelControl::reader_buffer.getLen()-1; ++i){
        if(values[i] > values[i+1]) {
          temp = values[i+1];
          values[i+1] = values[i];
          values[i] = temp;
        }
      }
    }
    //RODOS::PRINTF("meassured speed: %f current median: %f\n", temp_speed, values[5]);
    if(fabs(values[5]-temp_speed)>200.0f){
      ReactionWheelControl::medianRejections++;
      missed_val.setPins(~missed_val.readPins());
      ReactionWheelControl::rotation_speed = values[5];
    }
    else{
      //RODOS::PRINTF("takin real: %f\n", temp_speed);
      ReactionWheelControl::rotation_speed = temp_speed;
    }

    
  }
  else{

      ReactionWheelControl::rotation_speed = temp_speed;

  }
}

//own methods

void ReactionWheelControl::updateStdTM() {
	auto stdTM = this->standardTelemetry.access();
  stdTM->rotationSpeed = ReactionWheelControl::rotation_speed;
  stdTM->controllerOutput = ReactionWheelControl::control_output;
  stdTM->pwm = ReactionWheelControl::current_pwm;
  stdTM->desiredMotorSpeed = ReactionWheelControl::desired_speed;
  stdTM->medianRejections = ReactionWheelControl::medianRejections;
  stdTM->offset = offset;
}
