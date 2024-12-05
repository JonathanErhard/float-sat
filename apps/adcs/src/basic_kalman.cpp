#include "rodos.h"
using namespace RODOS;
#include "matlib.h"

// Kalman Filter class definition
class KalmanFilter {
public:
    // Kalman filter variables
    // do we need to include B and U
    
    //TODO

    Matrix3D_F A;
    Matrix3D_F B; 
    Matrix3D_F C;
    Matrix3D_F G;
    Matrix3D_F K;
    Vector3D_F u;
    Vector3D_F u_dist;
    Matrix3D_F I ; // <- this has to be an identity matrix. i hope it is
    double unew = 0; // step input = 1
    Matrix3D_F Q;  // Process noise covariance matrix
    Matrix3D_F R;  // Measurement noise covariance matrix
    Matrix3D_F P;  // Estimate error covariance matrix
    Matrix3D_F P_hat;  // Estimate error covariance matrix
    Vector3D_F x;  // State vector (e.g., pitch, roll, yaw)
    Vector3D_F x_hat;  // prediction of posteriori State vector (e.g., pitch, roll, yaw)
    Vector3D_F x_hatM;  // prediction of a prioiri State vector (e.g., pitch, roll, yaw)

    KalmanFilter() {
        // Initialize matrices
        //Q =      Eigen::Matrix<float, 3, 3>::Identity() * 0.01;  // Small process noise
        //R =      Eigen::Matrix<float, 3, 3>::Identity() * 0.1;   // Larger measurement noise
        //P =      Eigen::Matrix<float, 3, 3>::Identity();          // Initial error covariance
        //P_hat =  Eigen::Matrix<float, 3, 3>::Identity();          // Initial error covariance
        Q.r[0][0]=0.01;
        Q.r[1][1]=0.01;
        Q.r[2][2]=0.01;
        R.r[0][0]=0.1;
        R.r[2][2]=0.1;
        R.r[1][1]=0.1;



        //initial states:

        x.x=0; x.y=0; x.z=0;              // Initial state (pitch, roll, yaw)
        x_hat.x=0; x_hat.y=0; x_hat.z=0;           // a-priori state (pitch, roll, yaw)
        x_hatM.x =0; x_hatM.y=0; x_hatM.z=0;           // a-priori state (pitch, roll, yaw)

    }
    // Kalman filter predict step
    void predict(const Vector3D_F& gyroData, float dt) {
        // Predict the next state using gyro data (angular velocity)
        //x += gyroData * dt;  // State prediction based on gyro data and time step
        x = A* gyroData * dt + B * u; // original data
        u_dist = u; //+ 0.2/2 + 0.01 ;// /2 instead of using rand(1)
        x_hatM = A * x_hat + B * u_dist; // a-priori


        // Update error covariance using process noise
        // P_k+1 = A*P_k*AT + GQG^T
        P_hat = A * P * (A.invert()) + G * Q * (G.invert());
        //K = (P_hat * C) * (((C * P_hat * C.inverse()) + R).inverse()); this does not work, because c++ is stupid :)
        Matrix3D_F temp1 = P_hat * C;  // Evaluate the first matrix product
        Matrix3D_F temp2 = C * P_hat * C.invert() + R;  // Evaluate the second matrix product and addition
        Matrix3D_F temp3 = temp2.invert();  // Compute the inverse of the sum
        K = temp1 * temp3;

        P = P - (I - K * C) * P_hat;
    }
    
    // Kalman filter update step
    void update(const Vector3D_F& accelData,
                const Vector3D_F& magData) {
        // In real-world scenarios, we use accelerometer and magnetometer data to correct orientation.
        // For simplicity, we assume a model where accelData and magData directly give us a measurement of orientation.

        // Assume the accelerometer provides pitch and roll estimates
       
        Vector3D_F accelEstimate;
        accelEstimate.x= atan2(accelData.y, accelData.z);
        accelEstimate.y= atan2(-accelData.x, sqrt(accelData.y*accelData.y + accelData.z*accelData.z));
        accelEstimate.z= 0.0f;  // Assuming no yaw information from accelerometer

        // Magnetometer provides yaw estimate
        Vector3D_F magEstimate;
        magEstimate.x= 0.0f; 
        magEstimate.y=0.0f;
        magEstimate.z= atan2(magData.y, magData.x);

        // Combine accelerometer and magnetometer measurements
        Vector3D_F  z = ((accelEstimate + magEstimate)/2.0f) ;//+ R / 2.4); //z = (accelEstimate + magEstimate) / 2.0f;  // Average of both sensors

        // Compute Kalman gain
        //Matrix3D_F S = P + R;  // System uncertainty
        //Matrix3D_F K = P * S.inverse();  // Kalman gain

        // Update estimate
        x_hat = x_hatM + K * (z - C * x_hat);// a- posteriori

        // Update error covariance
        //P = (Eigen::Matrix<float, 3, 3>::Identity() - K) * P;
    }

    // Get the current estimate (pitch, roll, yaw)
    Vector3D_F  getState() {
        return x_hat;
    }
};
/*
// Main program to interface with the IMU and apply the Kalman filter
int main() {
    // Initialize Kalman filter
    KalmanFilter kf;

    // Placeholder IMU sensor data
    Vector3D_F accelData, gyroData, magData;

    // Simulate a basic loop where we read data from the sensors and apply the Kalman filter
    for (int i = 0; i < 1000; ++i) {
        // Get new sensor data (replace this with actual sensor readings)
        // For demonstration purposes, let's use some mock values
        accelData.x=0.0f;  // Accelerometer data (example)
        accelData.y=0.9f;  // Accelerometer data (example)
        accelData.z=9.8f;  // Accelerometer data (example)

        gyroData.x= 0.01f;  // Gyroscope data (example)
        gyroData.y= 0.01f;  // Gyroscope data (example)
        gyroData.z=0.01f;  // Gyroscope data (example)

        magData.x= 1.0f;  // Magnetometer data (example)
        magData.y= 0.0f;  // Magnetometer data (example)
        magData.z= 0.0f;  // Magnetometer data (example)

        // Call the predict step
        kf.predict(gyroData, 0.01f);  // Assuming a 10ms timestep

        // Call the update step (fuse data from accelerometer and magnetometer)
        kf.update(accelData, magData);

        // Get the filtered estimate (pitch, roll, yaw)
        Vector3D_F state = kf.getState();

        // Print the estimated orientation (pitch, roll, yaw)
        //std::cout << "Pitch: " << state[0] << " Roll: " << state[1] << " Yaw: " << state[2] << std::endl;

        // Simulate a delay (e.g., 10ms)
        //std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }

    return 0;
}*/
