//generated using CreateApp.sh

#include "adcs.h" 
#include "rodos.h"
using namespace RODOS;
#include "matlib.h"




// Kalman filter predict step
void Adcs::predict() { //const Vector3D_F& gyroData, float dt
	// Predict the next state using gyro data (angular velocity)
	//x += gyroData * dt;  // State prediction based on gyro data and time step
	Adcs::x = Adcs::A* Adcs::gyroData * Adcs::dt + Adcs::B * Adcs::u; // original data
	Adcs::u_dist = Adcs::u; //+ 0.2/2 + 0.01 ;// /2 instead of using rand(1)
	Adcs::x_hatM = Adcs::A * Adcs::x_hat + Adcs::B * Adcs::u_dist; // a-priori


	// Update error covariance using process noise
	// P_k+1 = A*P_k*AT + GQG^T
	Adcs::P_hat = Adcs::A * Adcs::P * (Adcs::A.invert()) + G * Q * (Adcs::G.invert());
	//K = (P_hat * C) * (((C * P_hat * C.inverse()) + R).inverse()); this does not work, because c++ is stupid :)
	Matrix3D_F temp1 = Adcs::P_hat * Adcs::C;  // Evaluate the first matrix product
	Matrix3D_F temp2 = Adcs::C * Adcs::P_hat * Adcs::C.invert() + Adcs::R;  // Evaluate the second matrix product and addition
	Matrix3D_F temp3 = temp2.invert();  // Compute the inverse of the sum
	Adcs::K = temp1 * temp3;

	Adcs::P = Adcs::P - (Adcs::I - Adcs::K * Adcs::C) * Adcs::P_hat;
}

// Kalman filter update step
void Adcs::update() { //const Vector3D_F& accelData,const Vector3D_F& magData
	// In real-world scenarios, we use accelerometer and magnetometer data to correct orientation.
	// For simplicity, we assume a model where accelData and magData directly give us a measurement of orientation.

	// Assume the accelerometer provides pitch and roll estimates
	
	Vector3D_F accelEstimate;
	accelEstimate.x= atan2(Adcs::accelData.y, Adcs::accelData.z);
	accelEstimate.y= atan2(-Adcs::accelData.x, sqrt(Adcs::accelData.y*Adcs::accelData.y + Adcs::accelData.z*Adcs::accelData.z));
	accelEstimate.z= 0.0f;  // Assuming no yaw information from accelerometer

	// Magnetometer provides yaw estimate
	Vector3D_F magEstimate;
	magEstimate.x= 0.0f; 
	magEstimate.y=0.0f;
	magEstimate.z= atan2(Adcs::magData.y, Adcs::magData.x);

	// Combine accelerometer and magnetometer measurements
	Vector3D_F  z = ((accelEstimate + magEstimate)/2.0f) ;//+ R / 2.4); //z = (accelEstimate + magEstimate) / 2.0f;  // Average of both sensors

	// Compute Kalman gain
	//Matrix3D_F S = P + R;  // System uncertainty
	//Matrix3D_F K = P * S.inverse();  // Kalman gain

	// Update estimate
	Adcs::x_hat = Adcs::x_hatM + Adcs::K * (z - Adcs::C * Adcs::x_hat);// a- posteriori

	// Update error covariance
	//P = (Eigen::Matrix<float, 3, 3>::Identity() - K) * P;
}

// Get the current estimate (pitch, roll, yaw)
Vector3D_F  Adcs::getState() {
	return Adcs::x_hat;
}



void Adcs::initialize(){
	// Initialize matrices
	//Q =      Eigen::Matrix<float, 3, 3>::Identity() * 0.01;  // Small process noise
	//R =      Eigen::Matrix<float, 3, 3>::Identity() * 0.1;   // Larger measurement noise
	//P =      Eigen::Matrix<float, 3, 3>::Identity();          // Initial error covariance
	//P_hat =  Eigen::Matrix<float, 3, 3>::Identity();          // Initial error covariance
	Adcs::Q.r[0][0]=0.01;
	Adcs::Q.r[1][1]=0.01;
	Adcs::Q.r[2][2]=0.01;
	Adcs::R.r[0][0]=0.1;
	Adcs::R.r[2][2]=0.1;
	Adcs::R.r[1][1]=0.1;

	int64_t h=Adcs::examplethreadThread.getPeriod();
	Adcs::dt;


	//initial states:

	Adcs::x.x=0; Adcs::x.y=0; Adcs::x.z=0;              // Initial state (pitch, roll, yaw)
	Adcs::x_hat.x=0; Adcs::x_hat.y=0; Adcs::x_hat.z=0;           // a-priori state (pitch, roll, yaw)
	Adcs::x_hatM.x =0; Adcs::x_hatM.y=0; Adcs::x_hatM.z=0;           // a-priori state (pitch, roll, yaw)

}


//Thread methods
void Adcs::initExamplethread() {

}

void Adcs::runExamplethread() {
	// Initialize Kalman filter

    // Placeholder IMU sensor data
	float tempacc[3];
	float tempgyro[3];
	float tempmag[3];
	float temp;
	imuDataTopic.getOnlyIfNewData(tempacc,tempgyro,tempmag,temp);
// Simulate a basic loop where we read data from the sensors and apply the Kalman filter
		// Get new sensor data (replace this with actual sensor readings)
	// For demonstration purposes, let's use some mock values
	Adcs::accelData.x=tempacc[0];  // Accelerometer data (example)
	Adcs::accelData.y=tempacc[1] ;  // Accelerometer data (example)
	Adcs::accelData.z=tempacc[2] ;  // Accelerometer data (example)

	Adcs::gyroData.x= tempgyro[0];  // Gyroscope data (example)
	Adcs::gyroData.y= tempgyro[1];  // Gyroscope data (example)
	Adcs::gyroData.z=tempgyro[2];  // Gyroscope data (example)

	Adcs::magData.x= tempmag[0];  // Magnetometer data (example)
	Adcs::magData.y= tempmag[1];  // Magnetometer data (example)
	Adcs::magData.z= tempmag[2];  // Magnetometer data (example)

	// Call the predict step
	predict();  // Assuming a 10ms timestep

	// Call the update step (fuse data from accelerometer and magnetometer)
	update();

	// Get the filtered estimate (pitch, roll, yaw)
	Vector3D_F state = getState();
	RODOS::PRINTF(state)
	generated::attitudeDeterminationTopic.publish(state.x,stat.y);

	// Print the estimated orientation (pitch, roll, yaw)
	//std::cout << "Pitch: " << state[0] << " Roll: " << state[1] << " Yaw: " << state[2] << std::endl;

	// Simulate a delay (e.g., 10ms)
	//std::this_thread::sleep_for(std::chrono::milliseconds(10));
}


//Telecommand methods
bool Adcs::handleTelecommandNOP() {
	RODOS::PRINTF("ADCS:ADCS_NOP\n");
	return false;
}

