//generated using CreateApp.sh

#include <adcs-generated/adcs.h> 
#include "ringbuffer.h"

#include "stm32f4xx_conf.h"
#include "math.h"
#include "stdint.h"
#include "MedianFilter.h"


class Adcs: public generated::Adcs{

	public:

		void initialize() override;

		//Thread methods
		void initAdcsThreat() override;
		void runAdcsThreat() override;

		//Telecommand methods
		bool handleTelecommandNOP() override;
		bool handleTelecommandSetControlMode(const generated::SetControlMode &setControlMode) override;
    bool handleTelecommandSafePowerUpDown(const generated::SafePowerUpDown &powerupdown) override;
    bool handleTelecommandSetPid(const generated::SetPid& setPid) override;

		//Topic methods
		void handleTopicImuDataTopic(generated::ImuDataTopic &message) override;
		void handleTopicModeTopic(generated::ModeTopic &message) override;

    void updateStdTM();


		generated::ImuDataTopic imu;
		generated::ModeTopic mode;
    generated::SetControlMode controlMode;
    generated::AttitudeDeterminationTopic attTopic;

    RODOS::RingBuffer<Vector3D_F, 10> positionRb;
    RODOS::RingBuffer<Vector3D_F, 10> velocityRb;

  private:
  //----------------------------this is for determination-------------------------------------------------------------------
    void update(const Matrix_<1,1,float> & y, float u);//update the kalman filter
    void updateDt();//update the Time 
    float mod(float in);


    Matrix_<2,2,float> A; //Matrixes for the filter
    Matrix_<2,1,float> G;
    Matrix_<1,2,float> C;
    Matrix_<2,2,float> Q;
    Matrix_<1,1,float> R;
    Matrix_<2,2,float> P;
    Matrix_<2,1,float> K;

    double t; // Time of the Last measurement
    double dt; // Discrete time step
    bool initialized;  // Is the filter initialized?
    double R_Gyro; //gyro bias

    Matrix_<2,2,float>  I;  // n-size identity
    Matrix_<2,1,float>  x_hat, x_hat_new;  // Estimated states


    //----------------------------this is for control-------------------------------------------------------------------
    float pid();

    float target_att = 0, target_speed =0,target_RPM=0; //target attitude and speed

    float vel, pos=0;
    float pitch,roll;

    bool safePowerDown=false;

    float k_pos[3];
	  float k_v_sat[3];
    float k_v_wheel[3];

    float k1, k2, k3, //pos
    k4, k5, k6, //v sat
    k7, k8, k9; //pid values
    float dt_pid;
    float last_input, last_time;
    float motor_speed_measured;
    float sum_error1, sum_error2, sum_error3=0;
    float init_time;

    void motorController(float input);
    void EncoderInit();
    void MotorSpeedUpdate();
    MedianFilter<float, 10> motorFilter;
    void calculaterise();
    void testRPM();
    
    float desired_speed;
private:
    long time;
    float testValue=2000;
    float testsquares=0;
    float testcounter=0;
    int steps_telecomand;
    float error2, error1;
    float last_error1=0;
    float last_error2=0;
    float last_error3=0;




};
