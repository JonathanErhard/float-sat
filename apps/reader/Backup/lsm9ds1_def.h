/*
 * LSM9DS1_reg.h
 *
 *  Created on: Jan 31, 2017
 *      Author: strohmi
 */

#ifndef LSM9DS1_REG_H_
#define LSM9DS1_REG_H_

#define LSM9DS1_XG_ID 					0b01101000
#define LSM9DS1_M_ID 					0b00111101

/////////////////////////////////////////
// LSM9DS1 Accel/Gyro (XL/G) Registers //
/////////////////////////////////////////
#define LSM9DS1_ACT_THS				0x04
#define LSM9DS1_ACT_DUR				0x05
#define LSM9DS1_INT_GEN_CFG_XL		0x06
#define LSM9DS1_INT_GEN_THS_X_XL	0x07
#define LSM9DS1_INT_GEN_THS_Y_XL	0x08
#define LSM9DS1_INT_GEN_THS_Z_XL	0x09
#define LSM9DS1_INT_GEN_DUR_XL		0x0A
#define LSM9DS1_REFERENCE_G			0x0B
#define LSM9DS1_INT1_CTRL			0x0C
#define LSM9DS1_INT2_CTRL			0x0D
#define LSM9DS1_WHO_AM_I_XG			0x0F
#define LSM9DS1_CTRL_REG1_G			0x10
#define LSM9DS1_CTRL_REG2_G			0x11
#define LSM9DS1_CTRL_REG3_G			0x12
#define LSM9DS1_ORIENT_CFG_G		0x13
#define LSM9DS1_INT_GEN_SRC_G		0x14
#define LSM9DS1_OUT_TEMP_L			0x15
#define LSM9DS1_OUT_TEMP_H			0x16
#define LSM9DS1_STATUS_REG_0		0x17
#define LSM9DS1_OUT_X_L_G			0x18
#define LSM9DS1_OUT_X_H_G			0x19
#define LSM9DS1_OUT_Y_L_G			0x1A
#define LSM9DS1_OUT_Y_H_G			0x1B
#define LSM9DS1_OUT_Z_L_G			0x1C
#define LSM9DS1_OUT_Z_H_G			0x1D
#define LSM9DS1_CTRL_REG4			0x1E
#define LSM9DS1_CTRL_REG5_XL		0x1F
#define LSM9DS1_CTRL_REG6_XL		0x20
#define LSM9DS1_CTRL_REG7_XL		0x21
#define LSM9DS1_CTRL_REG8			0x22
#define LSM9DS1_CTRL_REG9			0x23
#define LSM9DS1_CTRL_REG10			0x24
#define LSM9DS1_INT_GEN_SRC_XL		0x26
#define LSM9DS1_STATUS_REG_1		0x27
#define LSM9DS1_OUT_X_L_XL			0x28
#define LSM9DS1_OUT_X_H_XL			0x29
#define LSM9DS1_OUT_Y_L_XL			0x2A
#define LSM9DS1_OUT_Y_H_XL			0x2B
#define LSM9DS1_OUT_Z_L_XL			0x2C
#define LSM9DS1_OUT_Z_H_XL			0x2D
#define LSM9DS1_FIFO_CTRL			0x2E
#define LSM9DS1_FIFO_SRC			0x2F
#define LSM9DS1_INT_GEN_CFG_G		0x30
#define LSM9DS1_INT_GEN_THS_XH_G	0x31
#define LSM9DS1_INT_GEN_THS_XL_G	0x32
#define LSM9DS1_INT_GEN_THS_YH_G	0x33
#define LSM9DS1_INT_GEN_THS_YL_G	0x34
#define LSM9DS1_INT_GEN_THS_ZH_G	0x35
#define LSM9DS1_INT_GEN_THS_ZL_G	0x36
#define LSM9DS1_INT_GEN_DUR_G		0x37

///////////////////////////////
// LSM9DS1 Magneto Registers //
///////////////////////////////
#define LSM9DS1_OFFSET_X_REG_L_M	0x05
#define LSM9DS1_OFFSET_X_REG_H_M	0x06
#define LSM9DS1_OFFSET_Y_REG_L_M	0x07
#define LSM9DS1_OFFSET_Y_REG_H_M	0x08
#define LSM9DS1_OFFSET_Z_REG_L_M	0x09
#define LSM9DS1_OFFSET_Z_REG_H_M	0x0A
#define LSM9DS1_WHO_AM_I_M			0x0F
#define LSM9DS1_CTRL_REG1_M			0x20
#define LSM9DS1_CTRL_REG2_M			0x21
#define LSM9DS1_CTRL_REG3_M			0x22
#define LSM9DS1_CTRL_REG4_M			0x23
#define LSM9DS1_CTRL_REG5_M			0x24
#define LSM9DS1_STATUS_REG_M		0x27
#define LSM9DS1_OUT_X_L_M			0x28
#define LSM9DS1_OUT_X_H_M			0x29
#define LSM9DS1_OUT_Y_L_M			0x2A
#define LSM9DS1_OUT_Y_H_M			0x2B
#define LSM9DS1_OUT_Z_L_M			0x2C
#define LSM9DS1_OUT_Z_H_M			0x2D
#define LSM9DS1_INT_CFG_M			0x30
#define LSM9DS1_INT_SRC_M			0x31
#define LSM9DS1_INT_THS_L_M			0x32
#define LSM9DS1_INT_THS_H_M			0x33

////////////////////////////////////
// LSM9DS1 Accelerometer Settings //
////////////////////////////////////
//Acclerometer ODR
#define LSM9DS1_X_ODR_10HZ				0x20
#define LSM9DS1_X_ODR_50HZ				0x40
#define LSM9DS1_X_ODR_119HZ				0x60
#define LSM9DS1_X_ODR_238HZ				0x80
#define LSM9DS1_X_ODR_476HZ				0xA0
#define LSM9DS1_X_ODR_952HZ				0xC0
//Acclerometer FullScale
#define LSM9DS1_X_FS_2G					0x00
#define LSM9DS1_X_FS_4G					0x10
#define LSM9DS1_X_FS_8G					0x18
#define LSM9DS1_X_FS_16G				0x08
//Acclerometer AntiAlias BW
#define LSM9DS1_X_BW_AUTO				0x00
#define LSM9DS1_X_BW_50HZ				0x07
#define LSM9DS1_X_BW_105HZ				0x06
#define LSM9DS1_X_BW_211HZ				0x05
#define LSM9DS1_X_BW_408HZ				0x04

#define LSM9DS1_X_HR_ON					0X80
#define LSM9DS1_X_HR_OFF				0X00
#define LSM9DS1_X_DCF_50				0x00
#define LSM9DS1_X_DCF_100				0x20
#define LSM9DS1_X_DCF_9					0x40
#define LSM9DS1_X_DCF_400				0x60

// INT1_CTRL_REG
#define LSM9DS1_INT1_IG_G				0x80
#define LSM9DS1_INT1_IG_XL				0x40
#define LSM9DS1_INT1_FSS5				0x20
#define LSM9DS1_INT1_OVR				0x10
#define LSM9DS1_INT1_FTH				0x08
#define LSM9DS1_INT1_Boot				0x04
#define LSM9DS1_INT1_DRDY_G				0x02
#define LSM9DS1_INT1_DRDY_XL			0x01

// INT2_CTRL_REG
#define LSM9DS1_INT2_FSS5				0x20
#define LSM9DS1_INT2_OVR				0x10
#define LSM9DS1_INT2_FTH				0x08
#define LSM9DS1_INT2_DRDY_TEMP			0x04
#define LSM9DS1_INT2_DRDY_G				0x02
#define LSM9DS1_INT2_DRDY_XL			0x01


/////////////////////////////////
// LSM9DS1 Gyroscope  Settings //
/////////////////////////////////
//Gyroscope ODR
#define LSM9DS1_G_ODR_15HZ				0x20
#define LSM9DS1_G_ODR_60HZ				0x40
#define LSM9DS1_G_ODR_119HZ				0x60
#define LSM9DS1_G_ODR_238HZ				0x80
#define LSM9DS1_G_ODR_476HZ				0xA0
#define LSM9DS1_G_ODR_952HZ				0xC0
//Gyroscope Full-Scale DPS
#define LSM9DS1_G_FS_245				0x00
#define LSM9DS1_G_FS_500				0x08
#define LSM9DS1_G_FS_2000				0x18
//Gyroscope CutOff Hz after LPF2
#define LSM9DS1_G_LPF2_LOW				0x00
#define LSM9DS1_G_LPF2_LMID				0x01
#define LSM9DS1_G_LPF2_HMID				0x02
#define LSM9DS1_G_LPF2_HIGH				0x03

//////////////////////////////
// LSM9DS1 Magneto Settings //
//////////////////////////////
// ODR, Performance mode XY
#define LSM9DS1_M_TEMP_COMP				0x80
#define LSM9DS1_M_OM_XY_LOW				0x00
#define LSM9DS1_M_OM_XY_MEDIUM			0x20
#define LSM9DS1_M_OM_XY_HIGH			0x40
#define LSM9DS1_M_OM_XY_ULTRA			0x60
#define LSM9DS1_M_ODR_0P625				0x00
#define LSM9DS1_M_ODR_1P25				0x04
#define LSM9DS1_M_ODR_2P5				0x08
#define LSM9DS1_M_ODR_5					0x0C
#define LSM9DS1_M_ODR_10				0x10
#define LSM9DS1_M_ODR_20				0x14
#define LSM9DS1_M_ODR_40				0x18
#define LSM9DS1_M_ODR_80				0x1C
#define LSM9DS1_M_FAST_ODR 				0x02
// ODR, Full Scale
#define LSM9DS1_M_FS_4					0x00
#define LSM9DS1_M_FS_8					0x02
#define LSM9DS1_M_FS_12					0x04
#define LSM9DS1_M_FS_16 				0x06
// Device Mode
#define LSM9DS1_M_I2C_DISABLE			0x80
#define LSM9DS1_M_SPI_ENABLE			0x40
#define LSM9DS1_M_MD_CONT				0x00
#define LSM9DS1_M_MD_SINGLE				0x01
#define LSM9DS1_M_MD_OFF				0x10

// Performance Mode Z
#define LSM9DS1_M_OM_Z_LOW				0x00
#define LSM9DS1_M_OM_Z_MEDIUM			0x06
#define LSM9DS1_M_OM_Z_HIGH				0x08
#define LSM9DS1_M_OM_Z_ULTRA			0x0C

// Acceleration LSB
#define LSM9DS1_ACCEL_MG_LSB_2G 		0.061F
#define LSM9DS1_ACCEL_MG_LSB_4G 		0.122F
#define LSM9DS1_ACCEL_MG_LSB_8G 		0.244F
#define LSM9DS1_ACCEL_MG_LSB_16G 		0.732F

// Angular Rate: dps per LSB
#define LSM9DS1_GYRO_DPS_DIGIT_245DPS 	0.00875F
#define LSM9DS1_GYRO_DPS_DIGIT_500DPS 	0.01750F
#define LSM9DS1_GYRO_DPS_DIGIT_2000DPS 	0.07000F

// Magnetic Field Strength gauss range
#define LSM9DS1_MAG_MGAUSS_4GAUSS 		0.14F
#define LSM9DS1_MAG_MGAUSS_8GAUSS 		0.29F
#define LSM9DS1_MAG_MGAUSS_12GAUSS 		0.43F
#define LSM9DS1_MAG_MGAUSS_16GAUSS 		0.58F

// Temperature
#define LSM9DS1_TEMP_LSB_PER_C			16
#define LSM9DS1_TEMP_OFFSET				25

#endif /* LSM9DS1_REG_H_ */
