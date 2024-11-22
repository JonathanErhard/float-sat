//generated using CreateApp.sh

#include <reader-generated/reader.h> 

	HAL_GPIO *csXG;
	HAL_GPIO *csM;
	HAL_GPIO *imuEN;
	bool isEye;

	Matrix3D_F rot;

	/*uint8_t rxBuf[12] = { 0 };
	uint8_t txBuf[3] = { 0 };
	int32_t error[1] = { 0 };*/

    

class Reader: public generated::Reader{

	private:
	bool readAcc(RODOS::Vector3D_F &data);
	bool readGyro(RODOS::Vector3D_F &data);	
	bool readMag(RODOS::Vector3D_F &data);
	bool readTemp(float &temperature);

	public:

	void initialize() override;

	//Thread methods
	void initReadthreat() override;
	void runReadthreat() override;

	//Telecommand methods
	bool handleTelecommandNOP() override;
};
