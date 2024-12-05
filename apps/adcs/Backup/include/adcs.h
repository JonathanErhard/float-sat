//generated using CreateApp.sh

#include <adcs-generated/adcs.h> 

class Adcs: public generated::Adcs{

	public:

	void initialize() override;

	//Thread methods
	void initExamplethread() override;
	void runExamplethread() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;


//shit i copied from yusef

	void predict();

	void update();

	Vector3D_F  getState();

	private:
		Matrix3D_F A;
		Matrix3D_F B; 
		Matrix3D_F C;
		Matrix3D_F G;
		Matrix3D_F K;
		Vector3D_F u;
		Vector3D_F u_dist;
		Matrix3D_F I ; // <- this has to be an identity matrix. i hope it is
		//double u = 0; // step input = 1
		double dt;
		Matrix3D_F Q;  // Process noise covariance matrix
		Matrix3D_F R;  // Measurement noise covariance matrix
		Matrix3D_F P;  // Estimate error covariance matrix
		Matrix3D_F P_hat;  // Estimate error covariance matrix
		Vector3D_F x;  // State vector (e.g., pitch, roll, yaw)
		Vector3D_F x_hat;  // prediction of posteriori State vector (e.g., pitch, roll, yaw)
		Vector3D_F x_hatM;  // prediction of a prioiri State vector (e.g., pitch, roll, yaw)

		Vector3D_F accelData, gyroData, magData;


};
