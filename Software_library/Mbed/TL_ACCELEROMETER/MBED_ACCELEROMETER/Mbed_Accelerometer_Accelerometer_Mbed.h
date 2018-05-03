#ifndef MBED_ACCELEROMETER_ACCELEROMETER_MBED_H
#define MBED_ACCELEROMETER_ACCELEROMETER_MBED_H
#include <cstdio>
#include <cstdlib>
#include "mbed.h"
#include "TL_Config.h"
//located in ../library/eMPL_MPU6050
#include "mbed_i2c.h"
#include "inv_mpu.h"
#include "inv_mpu_dmp_motion_driver.h"
//located in ../library/nRF51822/TARGET_MCU_NRF51822/sdk/source/device
#include "nrf51.h"
#include "nrf51_bitfields.h"

#include "math.h"

#define MPU6050_SDA p12
#define MPU6050_SCL p13

#define DEFAULT_MPU_HZ (100)

class Mbed_Accelerometer_Accelerometer_Mbed{
private:
	unsigned long sensor_timestamp;
	short accel[3];
	int state;
	unsigned short accel_fsr=2,accel_rate;
	int setFSR(unsigned short fsr);
public:
	Mbed_Accelerometer_Accelerometer_Mbed();
	/*	
		初始化加速度传感器
		sample_rate:采样频率 范围4HZ~1KHZ
		accel_fsr:加速度传感器量程2/4/8/16g
		返回0，初始化成功
		1-传感器初始化失败
	*/
	int read();
    	double data_x();
	double data_y();
	double data_z();
};

extern Mbed_Accelerometer_Accelerometer_Mbed TL_Accelerometer;

#endif
