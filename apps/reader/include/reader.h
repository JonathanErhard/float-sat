//generated using CreateApp.sh

#include <reader-generated/reader.h> 

	HAL_GPIO *csXG;
	HAL_GPIO *csM;
	HAL_GPIO *imuEN;
	bool isEye;
	float accConv, gyroConv, magConv;
	#define LSM9DS1_GYRO_DPS_DIGIT_500DPS 	0.01750F
	#define LSM9DS1_MAG_MGAUSS_4GAUSS 		0.14F
	#define LSM9DS1_ACCEL_MG_LSB_4G 		0.122F
	/*LSM9DS1(HAL_SPI *spi, HAL_GPIO *csXG, HAL_GPIO *csM, uint32_t spi_clk_rate=1000000, Semaphore *sem = NULL, HAL_GPIO *imuEN = NULL);
	LSM9DS1(HAL_SPI *spi, HAL_GPIO *csXG, HAL_GPIO *csM, Matrix3D_F rot, uint32_t spi_clk_rate=1000000,  Semaphore *sem = NULL, HAL_GPIO *imuEN = NULL);*/

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
