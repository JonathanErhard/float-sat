//generated using CreateApp.sh

/**
 * Filter is changed from
 * @author: Hayk Martirosyan
 * @date: 2014.11.15
 * 
 * Author rest:
 * @author Felix Brandner
 * @date 7.1.2025
 */

#include "adcs.h" 
#include "matlib.h"
#include "ringbuffer.h"
#include "hal_gpio.h"
#include "hal_pwm.h"

	#define freqPWM 5000	//TODO check if values ok (just stole them)
	#define MaxDeltaPWM 100
	#define MaxPWM 1000
    HAL_PWM PWM1(PWM_IDX02);
    HAL_PWM PWM2(PWM_IDX01);

	#define maxDesiredSpeed 100 //TODO check these values
	#define maxAttitude 100
//PE13//PE11
	//coppied from Senors.cpp written by Atheel Redah @ University of Würzburg, January 20, 2019
	/* Private variables ---------------------------------------------------------*/

HAL_GPIO missed_val(RODOS::GPIO_PIN::GPIO_061);

#define ADC01               ADC_IDX1       			// ADC1
#define ADCChannel          ADC_CH_001     			// PA1
#define ADCRes              4095                    // ADC full scale resolution of 12 bits = 2^12-1 = 4095
#define ADCRef              3000.0             // ADC adc reference voltage  = 3V = 3000mV
#define CurrentVoltageRatio 500                     //Current-sense feedback voltage of approximately 500 mV per amp

void Adcs::initialize(){
	for(int i=0;i<10;i++){
		Adcs::positionRb.put(Vector3D_F(0,0,0));
	}

	Adcs::R_Gyro = 0.001;
	Adcs::dt = Adcs::adcsThreatThread.getPeriod()/100000000;
    Adcs::dt = Adcs::dt/10;//halts maul, ich weiß dass es hässlig ist aber wir machen das so. deine mama ist hässlich.
	Adcs::dt=0.02;
	float factor=0.978;


	A.r[0][0]=1;							
	A.r[0][1]=factor*Adcs::dt;
	A.r[1][0]=0;
	A.r[1][1]=factor*1;

	G.r[0][0]=(1-factor)*Adcs::dt;					
	G.r[0][1]=(1-factor);//1;

	C.r[0][0]=1;
	C.r[0][1]=0;

	Q.r[0][0]=dt*dt * R_Gyro;		
	Q.r[0][1]=dt*R_Gyro;
	Q.r[1][0]=dt*R_Gyro;
	Q.r[1][1]=R_Gyro;

	R.r[0][0]=10;							

	P.r[0][0]=1.;							
	P.r[1][1]=1.;

	I.r[0][0]=1.;							
	I.r[1][1]=1.;

	RODOS::PRINTF("dt: %f \n",Adcs::dt);
	RODOS::PRINTF("Rgyro: %f \n",Adcs::R_Gyro);
	RODOS::PRINTF("A: %f %f\n   %f %f\n",Adcs::A.r[0][0],Adcs::A.r[0][1],Adcs::A.r[1][0],Adcs::A.r[1][1]);
	RODOS::PRINTF("G: %f \n   %f \n",Adcs::G.r[0][0],Adcs::G.r[0][1]);
	RODOS::PRINTF("C: %f \n   %f \n",Adcs::C.r[0][0],Adcs::C.r[0][1]);
	RODOS::PRINTF("Q: %f %f\n   %f %f\n",Adcs::Q.r[0][0],Adcs::Q.r[0][1],Adcs::Q.r[1][0],Adcs::Q.r[1][1]);
	RODOS::PRINTF("R: %f \n",Adcs::R.r[0][0]);
	RODOS::PRINTF("P: %f %f\n   %f %f\n",Adcs::P.r[0][0],Adcs::P.r[0][1],Adcs::P.r[1][0],Adcs::P.r[1][1]);
	RODOS::PRINTF("P: %f %f\n   %f %f\n",Adcs::I.r[0][0],Adcs::I.r[0][1],Adcs::I.r[1][0],Adcs::I.r[1][1]);
	Adcs::initialized=true;						//all initiialized

	mode.mode=0;
	Adcs::target_att=0;
	


	//PWM1.init(freqPWM,MaxPWM); //TODO
	//PWM2.init(freqPWM,MaxPWM);
	EncoderInit();
	k1=0.1;
	k2=0.0;
	k3=1.0;
	k4=0.1;
	k5=0.0;
	k6=1.0;
	k7=0.1;
	k8=0.0;
	k9=1.0;
}


//Thread methods
void Adcs::initAdcsThreat() {

}

void Adcs::runAdcsThreat() {
}


//Telecommand methods
bool Adcs::handleTelecommandNOP() {
	return false;
}

bool Adcs::handleTelecommandSetControlMode(const generated::SetControlMode &setControlMode) {
	Adcs::controlMode=setControlMode;
	if(controlMode.mode==0)
		Adcs::target_att=Adcs::x_hat.r[0][0];
	if(controlMode.mode==1)
		Adcs::target_att=controlMode.submode;
	if(controlMode.mode==2)
		Adcs::target_speed=controlMode.submode;
	return true;
}


//Topic methods
void Adcs::handleTopicImuDataTopic(generated::ImuDataTopic &message) {
	Adcs::imu = message;
	float u=(imu.gyroscope[2])-1;
	//float cz= atan2f(cx,cy);

	float r2 = imu.gyroscope[2];
	float p2 = (imu.magnetometer[0]);
	float y2 = (imu.magnetometer[1]);
	float cz= atan2(p2,y2) * 180/M_PI + 180;
	if(cz > 180) cz = -360+cz;
	else if(cz < -180) cz = 360+cz;
	
	Matrix_<1,1,float> peter;
	peter.r[0][0]=cz;

	updateDt();
	update(peter,u);


	updateStdTM();
	//attitudeDeterminationTopic.publish(Adcs::x_hat.r[0][0],Adcs::x_hat.r[0][1]);
	//RODOS::PRINTF("Pose: %f %f | %f %f\n",Adcs::x_hat.r[0][0],Adcs::x_hat.r[1][0], cz, u);

		Vector3D_F rpy(0,0,0);

	float mx = imu.magnetometer[0];
	float my = imu.magnetometer[1];
	float mz = imu.magnetometer[2];
	float r = imu.gyroscope[0]*float(M_PI/180);
	float p = imu.gyroscope[1]*float(M_PI/180);
	float y = imu.gyroscope[2]*float(M_PI/180/100);
	float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
	float cy = my*cos(r) + mz*sin(r) ;
	Adcs::positionRb.put(Vector3D_F(cx, cy,y));
	//Adcs::positionRb.put(Vector3D_F(p2, y2,y));
	for(int i =0;i<10;i++){
		rpy.x += Adcs::positionRb.vals[i].x;	
		rpy.y += Adcs::positionRb.vals[i].y;
		rpy.z += Adcs::positionRb.vals[i].z;
	}
	float pos = atan2(rpy.x,rpy.y)+ rpy.z*0.1f/2.f;
	pos=pos* 180/M_PI+180;
	if(pos > 180) pos = -360+pos;
	else if(pos < -180) pos = 360+pos;


	velocityRb.put(Vector3D_F(imu.gyroscope[0],imu.gyroscope[1],imu.gyroscope[2]));
	Vector3D_F velSum(0,0,0);
	for(int i = 0; i < 10;i++){
		velSum.x+=velocityRb.vals[i].x;
		velSum.y+=velocityRb.vals[i].y;
		velSum.z+=velocityRb.vals[i].z;
	}																																								//imu.magnetometer[0], imu.magnetometer[1],imu.magnetometer[2]												
	float vel=velSum.z/10;	
	RODOS::PRINTF("Pose: %f %f | %f %f | %f %f | %f %f\n",Adcs::x_hat.r[0][0],Adcs::x_hat.r[1][0],pos,vel, cz, u,rpy.z*0.1f/2.f,atan2f(rpy.x,rpy.y)*180/M_PI);






	//RODOS::PRINTF("%f -> %f %f | %f %f | %f |%f %f %f | %f %f %f | %f %f\n",current_att,Adcs::x_hat.r[0][0],Adcs::x_hat.r[1][0],peter.r[0][0],u, dt, mx,my,mz, r,p,y, atan2(cx,cy),cz);
	

}
void Adcs::updateDt(){
	Adcs::dt= (RODOS::NOW()-Adcs::t)/1000000000;
	Adcs::t = RODOS::NOW();

//A.r[0][1]=dt;
	/*G.r[0][0]=dt;
	Q.r[0][0]=dt*dt * R_Gyro;		
	Q.r[0][1]=dt*R_Gyro;
	Q.r[1][0]=dt*R_Gyro;/**/

}

float Adcs::mod(float in){
	if( in < -180)
		in += 360;
	else if( in > 180)
		in -= 360;
	return in;
}


void Adcs::update(const Matrix_<1,1,float> & y, float u){

	if(!Adcs::initialized)
		RODOS::PRINTF("NOT INITIALIZED!!!!! WATCH OUT FOR SHARKS!!!!!");

	Adcs::x_hat_new = Adcs::A * Adcs::x_hat + Adcs::G * u;
	Adcs::x_hat_new.r[0][0] = mod(Adcs::x_hat_new.r[0][0]);
	Adcs::P = Adcs::A*Adcs::P*Adcs::A.transpose() + Adcs::Q;
	Adcs::K = Adcs::P*Adcs::C.transpose()*(Adcs::C*Adcs::P*Adcs::C.transpose() + Adcs::R).invert();
	Matrix_<1,1,float> error = (y - C*x_hat_new);
	error.r[0][0] = mod(error.r[0][0]);
	Adcs::x_hat_new = Adcs::x_hat_new + Adcs::K * error;
	Adcs::x_hat_new.r[0][0] = mod(Adcs::x_hat_new.r[0][0]); 
	Adcs::P = (Adcs::I - Adcs::K*Adcs::C)*Adcs::P;
	Adcs::x_hat = Adcs::x_hat_new;
}


/*
different modes:
	- mode 0: keep current attitude
	- mode 1: align attitude with target attitude
	- mode 2: align speed with target speed
*/
void Adcs::handleTopicModeTopic(generated::ModeTopic &message) {
	Adcs::mode = message;
	if(mode.mode==0)
		Adcs::target_att=Adcs::x_hat.r[0][0];
	if(mode.mode==1)
		Adcs::target_att=mode.submode;
	if(mode.mode==2)
		Adcs::target_speed=mode.submode;
}

float Adcs::pid(){
	Adcs::dt_pid=(RODOS::NOW()-Adcs::last_time)/1000000000;//update time intervall
	Adcs::last_time=RODOS::NOW();
	if(mode.mode!=2){
		float error= Adcs::x_hat.r[0][0] - Adcs::target_att; //controll loop for desired attitude

		Adcs::target_speed = 	error * Adcs::dt_pid * Adcs::k1 + 
						error / Adcs::dt_pid * Adcs::k2 + 
						error * Adcs::k3 ;
	}

										//if we need a speed instead we do this
	float error2= Adcs::x_hat.r[1][0] - Adcs::target_speed;
														//controll loop for desired spee
	float desired_speed = 	error2 * Adcs::dt_pid * Adcs::k4 + 
					error2 / Adcs::dt_pid * Adcs::k5 + 
					error2 * Adcs::k6 ;
	if(desired_speed >   maxDesiredSpeed) desired_speed = maxDesiredSpeed;
	if(desired_speed < - maxDesiredSpeed) desired_speed = - maxDesiredSpeed;


	MotorSpeedUpdate();
	float error3 = Adcs::motor_speed_measured-desired_speed; //check how far off we are from the actual speed

	float error4 = 	error3 * Adcs::dt_pid * Adcs::k7 + 
					error3 / Adcs::dt_pid * Adcs::k8 + 
					error3 * Adcs::k9 ;

	
	return error4;
}

void Adcs::motorController(float input){


	//float diff=Adcs::motor_speed_measured/Adcs::last_input;//check how near we are at the desired speed
	//input = input * diff;

	if(input-last_input>MaxDeltaPWM){ //if the change of input is too high make it the maximum change
		input=last_input+MaxDeltaPWM;
	}else if(input-last_input<MaxDeltaPWM){
		input=last_input-MaxDeltaPWM;
	}

	if(input>MaxPWM) //check if motor is exceeding max speed
		input =MaxPWM;
	else if(input< - MaxPWM)
		input= -MaxPWM;
	

	if(input<0){ //differentiates between positive and negative speed
		PWM1.write(input);
		PWM2.write(0.0);
	} else{
		PWM1.write(0.0);
		PWM2.write(input);
	}



	Adcs::last_input=input; //save the last input
}


void Adcs::updateStdTM(){
	auto stdTM = this->standardTelemetry.access();
	stdTM->attitude = Adcs::x_hat.r[0][0];
	stdTM->speed = Adcs::x_hat.r[1][0];
	stdTM->target_att = Adcs::target_att;
	stdTM->target_speed = Adcs::target_speed;
	stdTM->motor_speed = Adcs::motor_speed_measured;
}


//Methods coppied from Sensors.cpp written by Atheel Redah @ University of Würzburg, January 20, 2019

void Adcs::EncoderInit()
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
 	__IO uint32_t IC4ReadValue1 = 0, IC4ReadValue2 = 0, Capture = 0;
	__IO uint8_t CaptureNumber = 0;
	__IO uint32_t TIM2Freq = 0;
	__IO uint8_t EncoderB;
	__IO double CaptureTime;
void TIM2_IRQHandler(void)
{
  if(TIM_GetITStatus(TIM2, TIM_IT_CC4) == SET)
  {
    /* Clear TIM2 Capture compare interrupt pending bit */
    TIM_ClearITPendingBit(TIM2, TIM_IT_CC4);
    CaptureTime = NOW();
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
      if (IC4ReadValue2 > IC4ReadValue1){
        Capture = (IC4ReadValue2 - IC4ReadValue1);
      } else if (IC4ReadValue2 < IC4ReadValue1){
        Capture = ((0xFFFFFFFF - IC4ReadValue1) + IC4ReadValue2);
      }
      /* Frequency computation */
      TIM2Freq = (uint32_t) ((SystemCoreClock/2)) * 8 / Capture;
      CaptureNumber = 0;
    }
  }
}
}


//updates at which speed the motor is
	void Adcs::MotorSpeedUpdate()
{
	double SensorTime = ((NOW()-CaptureTime)/(double)MILLISECONDS);
	if (SensorTime>250) //minimum measured speed is 2 RPS(120 RPM). This can give us 250ms of minimum interval between interrupts (2 interrupts every one revolution).
	{
		TIM2Freq=0;
	}

	if (EncoderB)
	{
		Adcs::motor_speed_measured = -1*((float)TIM2Freq / 16) * 60;  //CCW
	}
	else {Adcs::motor_speed_measured = ((float)TIM2Freq / 16) * 60;}  //CW
}







/*
	Vector3D_F rpy(0,0,0);

	float mx = imu.magnetometer[0];
	float my = imu.magnetometer[1];
	float mz = imu.magnetometer[2];
	float r = imu.gyroscope[0]*float(M_PI/180);
	float p = imu.gyroscope[1]*float(M_PI/180);
	float y = imu.gyroscope[2]*float(M_PI/180/100);
	float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
	float cy = my*cos(r) + mz*sin(r) ;
	Adcs::magRB.put(Vector3D_F(cx, cy,y));

 //taking the average over the last 10 values
	for(int i =0;i<10;i++){
		rpy.x += Adcs::magRB.vals[i].x;	
		rpy.y += Adcs::magRB.vals[i].y;
		rpy.z += Adcs::magRB.vals[i].z;
	}

	float pos = atan2f(rpy.x,rpy.y)+ rpy.z/2.f;
	if(pos > 180) pos = -360+pos;
	else if(pos < -180) pos = 360+pos;
	RODOS::PRINTF("%f %f %f\n",pos,atan2f(rpy.x,rpy.y),rpy.z/2.f);



/*float pitchFromAccel = 0;
float rollFromAccel  = 0;

pitchFromAccel = atan(-accelerometer.x / sqrt(pow(accelerometer.y, 2) + pow(accelerometer.z, 2)));	
rollFromAccel = atan(accelerometer.y / sqrt(pow(accelerometer.x, 2) + pow(accelerometer.z, 2)));
// rollFromAccel = atan2(accelerometer.y, accelerometer.z);

// Complimentary Filter
_pitch = (_pitchGyroFavoring) * (_pitch + (gyroscope.y * (1.00 / _filterUpdateRate))) + (1.00 - _pitchGyroFavoring) * (pitchFromAccel);
_roll = (_rollGyroFavoring) * (_roll + (gyroscope.x * (1.00 / _filterUpdateRate))) + (1.00 - _rollGyroFavoring) * (rollFromAccel);*/

// The above code returns the angle in RADIANS

    //RODOS::PRINTF("\n");
	//RODOS::PRINTF("%f %f %f\n",imu.magnetometer[0],imu.magnetometer[1],imu.magnetometer[2]);
    //RODOS::PRINTF("%f %f %f\n",imu.accelerometer[0],imu.accelerometer[1],imu.accelerometer[2]);
    //RODOS::PRINTF("%f %f %f\n",imu.gyroscope[0],imu.gyroscope[1],imu.gyroscope[2]);}
		/*float mx = imu.magnetometer[0];
	float my = imu.magnetometer[1];
	float mz = imu.magnetometer[2];
	float r = (imu.gyroscope[0]-7.600)*float(M_PI/180);
	float p = (imu.gyroscope[1]-1.368 )*float(M_PI/180);
	float y = (imu.gyroscope[2]-0.829)*float(M_PI/180/100);
	float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
	float cy = my*cos(r) + mz*sin(r) ;
	float cz = atan2f(cx,cy);



	 //7.797 | 1.417 | 0.935 7.600 | 1.368 | 0.829
 	float mx = imu.magnetometer[0];
	float my = imu.magnetometer[1];
	float mz = imu.magnetometer[2];
	float r = imu.gyroscope[0]*float(M_PI/180);
	float p = imu.gyroscope[1]*float(M_PI/180);
	float y = imu.gyroscope[2]*float(M_PI/180/100);
	float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
	float cy = my*cos(r) + mz*sin(r) ;
	Adcs::positionRb.put(Vector3D_F(cx, cy,y));
	Vector3D_F rpy(0,0,0);
	for(int i =0;i<10;i++){
		rpy.x += Adcs::positionRb.vals[i].x;	
		rpy.y += Adcs::positionRb.vals[i].y;
		rpy.z += Adcs::positionRb.vals[i].z;
	}

	float pos2 = atan2f(rpy.x,rpy.y)+ rpy.z/2.f;
	if(pos2 > M_PI) pos2 = -2*M_PI+pos2;
	else if(pos2 < -M_PI) pos2 = 2*M_PI+pos2;
	
	
	
	
	*/


