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
	#define MaxDeltaPWM 5
	#define MaxPWM 990
	#define MinPWM 100
	#define MAXDrehrate 5000	//Max revolutions per minute that we can get
    HAL_PWM PWM1(PWM_IDX14);
    HAL_PWM PWM2(PWM_IDX15);

	#define maxDesiredSpeed 4000 //TODO check these values
	#define minDesiredSpeed-4000
	#define maxTargetSpeed 40
	#define minTargetSpeed -40
	
//PE13//PE11
	//coppied from Senors.cpp written by Atheel Redah @ University of Würzburg, January 20, 2019
	/* Private variables ---------------------------------------------------------*/
	__IO uint32_t IC4ReadValue1 = 0, IC4ReadValue2 = 0, Capture = 0;
	__IO uint8_t CaptureNumber = 0;
	__IO uint32_t TIM2Freq = 0;
	__IO uint8_t EncoderB;
	__IO double CaptureTime;

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
	float factor=0;


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
	


	PWM1.init(freqPWM,MaxPWM+10); //TODO
	PWM2.init(freqPWM,MaxPWM+10);
	last_input=0;
	EncoderInit();
	k_pos[0]=2.3;
	k_pos[1]=0.01;
	k_pos[2]=0.01;

	//VELOCITY CONTROLLER
	k_v_sat[0]=2.5;
	k_v_sat[1]=0.0093;
	k_v_sat[2]=0;
	
	//RPM CONTROLLER
	k_v_wheel[0]=2.79;
	k_v_wheel[1]=0.008;
	k_v_wheel[0]=0;

	time=RODOS::NOW();
	init_time=RODOS::NOW();
}


//Thread methods
void Adcs::initAdcsThreat() {

}


void Adcs::runAdcsThreat() {
	MotorSpeedUpdate();
	//calculates the speeds of the motor 
	//calculaterise();
	if(safePowerDown){
		Adcs::motorController(0);
		Adcs::sum_error3=0;
		Adcs::sum_error2=0;
		init_time=RODOS::NOW();
	}else{
		//if(RODOS::NOW()-init_time <20 * RODOS::SECONDS){
		//	Adcs::motorController(500);
		//}else if(RODOS::NOW()-init_time <60 * RODOS::SECONDS){
		//	//testRPM();
		//	testValue=2000;
		//	Adcs::motorController(pid());
		//} else{
			Adcs::motorController(pid());
		//}
		
		
	}
}


void Adcs::testRPM(){
	testValue+=5;
	testsquares += (Adcs::motor_speed_measured-desired_speed) * (Adcs::motor_speed_measured-desired_speed);
	testcounter++;

}

bool Adcs::handleTelecommandSetPid(const generated::SetPid& setPid){
	for(int i = 0;i<3;i++){
		switch(mode.mode){
		default:
			 Adcs::k_pos[i] = setPid.k_pos[i]; break;
		case 2: 
			Adcs::k_v_sat[i] = setPid.k_v_sat[i]; break;
		case 3: 
			Adcs::k_v_wheel[i] = setPid.k_v_wheel[i]; break;
		}
	}
	RODOS::PRINTF("kpos: %f \n kvsat %f\n kvwheel %f\n",k_pos[0],k_v_sat[0],k_v_wheel[0]);
	return false;
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

bool Adcs::handleTelecommandSafePowerUpDown(const generated::SafePowerUpDown &powerupdown){
	Adcs::safePowerDown=powerupdown.highRPM;
	PRINTF("Pull the Lever Kronk\n");
	return true;
}


//Topic methods
void Adcs::handleTopicImuDataTopic(generated::ImuDataTopic &message) {
	Adcs::imu = message;

	Vector3D_F rpy(0,0,0);
	float mx = imu.magnetometer[0];
	float my = imu.magnetometer[1];
	float mz = imu.magnetometer[2];
	

	pitch = atan2(imu.accelerometer[0],sqrt(imu.accelerometer[2]*imu.accelerometer[2]+imu.accelerometer[1]*imu.accelerometer[1]));//asin(imu.accelerometer[0]);
	roll  = atan2(imu.accelerometer[1],sqrt(imu.accelerometer[2]*imu.accelerometer[2]+imu.accelerometer[0]*imu.accelerometer[0]));//asin(imu.accelerometer[1]/cos(pitch));
	float Mx_h = mx*cos(pitch) +mz *sin(pitch);
	//mx*cos(pitch) + mz*sin(pitch);
    float My_h = mx*sin(roll) * sin(pitch) + my *cos(roll) - mz * sin(roll) * cos (pitch);
	//mx*sin(roll)*sin(pitch) + my*cos(roll) - mz*sin(roll)*cos(pitch);
	Adcs::positionRb.put(Vector3D_F(Mx_h, My_h,0));
	//Adcs::positionRb.put(Vector3D_F(p2, y2,y));
	for(int i =0;i<10;i++){
		rpy.x += Adcs::positionRb.vals[i].x;	
		rpy.y += Adcs::positionRb.vals[i].y;
		rpy.z += Adcs::positionRb.vals[i].z;
	}
	pos = atan2(rpy.x,rpy.y);//+ rpy.z*0.1f/2.f;
	//winkel dinkel berechnungen
		float r = imu.gyroscope[0]*float(M_PI/180);
		float p = imu.gyroscope[1]*float(M_PI/180);
		float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
   		float cy = my*cos(r) + mz*sin(r) ;
	//pos = atan2(Mx_h,My_h);
	//RODOS::PRINTF("-------------------------------\n roll %f \n pitch %f\n yaw %f \n Winkel yaw %f\n\n mx: %f \n my %f\n ",roll*180/M_PI,pitch*180/M_PI,pos*180/M_PI,atan2(cx,cy)*180/M_PI,Mx_h,My_h);
	

	velocityRb.put(Vector3D_F(imu.gyroscope[0],imu.gyroscope[1],imu.gyroscope[2]));
	Vector3D_F velSum(0,0,0);
	for(int i = 0; i < 10;i++){
		velSum.x+=velocityRb.vals[i].x;
		velSum.y+=velocityRb.vals[i].y;
		velSum.z+=velocityRb.vals[i].z;
	}																																								//imu.magnetometer[0], imu.magnetometer[1],imu.magnetometer[2]												
	vel=velSum.z/10;	
	x_hat.r[0][0]= pos;
	x_hat.r[0][1]= vel;
	updateStdTM();
	attTopic.velocity=vel;
	attTopic.position=pos *180/M_PI;
	attTopic.roll=roll*180/M_PI;
	attTopic.pitch=pitch*180/M_PI;
	attitudeDeterminationTopic.publish(attTopic);

	float rotation=0;
	float nu = tan(cos(rotation)*sin(attTopic.roll)+sin(rotation)*sin(attTopic.pitch));
	//RODOS::PRINTF("rpy: %f %f %f | vel: %f  | nu: %f \n",	attTopic.position,	attTopic.roll,	attTopic.pitch,	attTopic.velocity,nu);
	

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
		Adcs::target_att=Adcs::pos;
	if(mode.mode==1)
		Adcs::target_att=mode.submode;
	if(mode.mode==2)
		Adcs::target_speed=mode.submode;
	if(mode.mode==3)
		Adcs::desired_speed=mode.submode;
}

float Adcs::pid(){
	MotorSpeedUpdate();
	Adcs::dt_pid=(RODOS::NOW()-Adcs::last_time)/1000000000;//update time intervall
	Adcs::last_time=RODOS::NOW();
	if(mode.mode!=3){
		if(mode.mode!=2){
			float error1= Adcs::pos - Adcs::target_att; //controll loop for desired attitude
			Adcs::sum_error1 += sum_error1;
			Adcs::target_speed = 	Adcs::sum_error1 * Adcs::k_pos[1] + 
							(error1-last_error1) * k_pos[2] +
							error1 * Adcs::k_pos[0] ;
			Adcs::last_error1 = error1;
			if(target_speed > maxTargetSpeed) target_speed = maxTargetSpeed;
			if(target_speed < minTargetSpeed) target_speed = minTargetSpeed;
		}/**/

											//if we need a speed instead we do this
		float error2=  Adcs::target_speed - vel; //has to be this way round because actio = reactio
		Adcs::sum_error2 +=error2;
		desired_speed = 	error2 * Adcs::k_v_sat[0] + 
							sum_error2 * Adcs::k_v_sat[1] ;
	}
	desired_speed+=2000;
	//control_output_pi = ((reactWSpeed-2500)*0.5f - (satellite_velocity-Adcs::desired_velocity))/0.5f;
	if(desired_speed > maxDesiredSpeed)  desired_speed = maxDesiredSpeed;
	if(desired_speed < minDesiredSpeed)  desired_speed = minDesiredSpeed;/**/
	
	//desired_speed = Adcs::target_speed; //comment this in if you want to check the PID RPM values
	//desired_speed += maxDesiredSpeed/2;
	
	float error3 = (Adcs::motor_speed_measured-desired_speed); //check how far off we are from the actual speed
	Adcs::sum_error3 += error3;
	Adcs::target_RPM = 	error3 * Adcs::k_v_wheel[0] +
					Adcs::sum_error3 * Adcs::k_v_wheel[1] ;
	
	return target_RPM;	
}


bool flag=false;
void Adcs::motorController(float input){

		//RODOS::PRINTF("-----------------------------------\n DeltaPWM: %f\n k_v_wheel[1]: %f \nk_v_wheel[2]_: %f \nmotor speed: %f \ndesired Speed: %f \nRPM Error: %f \n input %f \n \n sumerror %f \n error %f\n"
		//	,input-last_input, k_v_wheel[1], k_v_wheel[2], motor_speed_measured, desired_speed,
		//	testsquares/testcounter,input, sum_error3,Adcs::motor_speed_measured-desired_speed);



	if(input-last_input>MaxDeltaPWM){ //if the change of input is too high make it the maximum change
		input=last_input+MaxDeltaPWM;
	}else if(input-last_input<-MaxDeltaPWM){
		input=last_input-MaxDeltaPWM;
	}
	
	if(input>MaxPWM) //check if motor is exceeding max speed
		input =MaxPWM;
	else if(input< - MaxPWM)
		input= -MaxPWM;
	//RODOS::PRINTF("%f %f %f\n ",input,motor_speed_measured, motor_speed_measured*500.000/2092.500);
	
	

	if(input>0){ //differentiates between positive and negative speed
		PWM1.write(abs(input));
		PWM2.write(0.0);
	} else{
		PWM1.write(0.0);
		PWM2.write(abs(input));
	}



	Adcs::last_input=input; //save the last input
}


void Adcs::updateStdTM(){
	if(RODOS::NOW() - time > 1 * RODOS::SECONDS){
        time=RODOS::NOW();
		auto stdTM = this->standardTelemetry.access();
		stdTM->attitudeYaw = pos * 180/M_PI;
		stdTM->speed = Adcs::x_hat.r[1][0];
		stdTM->target_att = Adcs::target_att;
		stdTM->target_speed = Adcs::target_speed;
		stdTM->motor_speed = Adcs::motor_speed_measured;
		stdTM->roll = Adcs::roll*180/M_PI;
		stdTM->pitch = Adcs::pitch*180/M_PI;
		stdTM->power_up=Adcs::safePowerDown;
		stdTM->target_RPM=Adcs::target_RPM;
		stdTM->controlMode=Adcs::mode.mode;
	}
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

     In this example TIM2 input clock (TIM2CLK) is set to 2 * APB1 clock (PCLk_pos[0]):
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
  RODOS::PRINTF("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
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
	//RODOS::PRINTF("captureNUmber: %d Capture %d Systemcoreclock; %d Time2freq %d\n", CaptureNumber,Capture,SystemCoreClock, TIM2Freq);
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
		motorFilter.addSample( -1*((float)TIM2Freq / 16) * 60);  //CCW
	}
	else {motorFilter.addSample(((float)TIM2Freq / 16) * 60);}  //CW
	//RODOS::PRINTF("I AM ALICE: %f %d\n", Adcs::motor_speed_measured, TIM2Freq);
	
	Adcs::motor_speed_measured = motorFilter.getMedian();
}

int angle = 500;
bool dir = 0;
double measure=0;
double sett=0;
int counter=0;
int time=0;
double res1,res2,res3=0;

void Adcs::calculaterise(){
MotorSpeedUpdate();
if(RODOS::NOW()-init_time <20 * RODOS::SECONDS){
	Adcs::motorController(300);
	time=20;
}else if(RODOS::NOW()-init_time <(30+time) * RODOS::SECONDS){
	Adcs::motorController(300);
	sett+=angle;
	measure+=motor_speed_measured;
	counter++;
	res1=sett/measure;
	time=50;
}else if(RODOS::NOW()-init_time <(20+time) * RODOS::SECONDS){
	Adcs::motorController(500);
	time=70;
	sett=0; measure=0; counter=0;
}else if(RODOS::NOW()-init_time <(30+time) * RODOS::SECONDS){
	Adcs::motorController(300);
	sett+=angle;
	measure+=motor_speed_measured;
	counter++;
	res2=sett/measure;
	time=100;
}else if(RODOS::NOW()-init_time <(20+time) * RODOS::SECONDS){
	Adcs::motorController(800);
	time=120;
	sett=0; measure=0; counter=0;
}else if(RODOS::NOW()-init_time <(30+time) * RODOS::SECONDS){
	Adcs::motorController(800);
	sett+=angle;
	measure+=motor_speed_measured;
	counter++;
	res3=sett/measure;
	time=160;
}else{
	Adcs::motorController(0);
	RODOS::PRINTF(" res1 %f res2 %f res3 %d res_average %f\n",res1,res2,res3,(res1+res2+res3)/3);
	
	}
}





/*
if(flag){
		if(abs(input)<5)
			input=0;
		else if(input< 0)
			input-=MinPWM;
		else 
			input +=MinPWM;

		if(input-last_input>MaxDeltaPWM){ //if the change of input is too high make it the maximum change
			input=last_input+MaxDeltaPWM;
		}else if(input-last_input<-MaxDeltaPWM){
			input=last_input-MaxDeltaPWM;
		}

		if(input>0 && abs(input)<MinPWM)
			input=-MinPWM;
		if(input<0 && abs(input)<MinPWM)
			input=MinPWM;
	}else{
//float r = imu.gyroscope[0]*float(M_PI/180); //asin(accelx/g);
	//float p = imu.gyroscope[1]*float(M_PI/180);
	//float y = imu.gyroscope[2]*float(M_PI/180/100);
	//float cx = mx*cos(p) + my*sin(r)*sin(p) - mz*cos(r)*sin(p);
	//float cy = my*cos(r) + mz*sin(r) ;
	//Adcs::positionRb.put(Vector3D_F(cx, cy,y));
//RODOS::PRINTF("input %f %f| %f | %f  %f\n ",input,last_input,motor_speed_measured, angle,(RODOS::NOW()-init_time )/ RODOS::SECONDS );
	//( angle <3 && angle > -3))
/*if(RODOS::NOW()-init_time <60 * RODOS::SECONDS || angle!=500){
	dir ? angle += 5: angle -= 5;
	if (angle > 900 || angle < 200)
		dir = !dir;
		Adcs::motorController(angle);*/
	// 500.000 2092.500
	//start 140
	// 250.000 948.750
	//4.185
	/*Vector3D_F rpy(0,0,0);

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
	
		/*float u=(imu.gyroscope[2])-1;
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
	*/


	//attitudeDeterminationTopic.publish(Adcs::x_hat.r[0][0],Adcs::x_hat.r[0][1]);
	//RODOS::PRINTF("Pose: %f %f | %f %f\n",Adcs::x_hat.r[0][0],Adcs::x_hat.r[1][0], cz, u);
	/*
	
	*/


