#ifndef GROVE_IMU9_ACCELEROMETER_BBB_H
#define GROVE_IMU9_ACCELEROMETER_BBB_H

#include "TL_Config.h"
#include "MPU9250_BBB.h"



class Grove_IMU9_Accelerometer_BBB{
private:
	MPU9250 accelgyro;
	int status;
	int16_t ax, ay, az;
public:
	Grove_IMU9_Accelerometer_BBB();
	int read();		
	void init();
	double data_x();
	double data_y();
	double data_z();
};

#if TINYLINK_ACCELEROMETER == GROVE_IMU9
	extern Grove_IMU9_Accelerometer_BBB TL_Accelerometer;
#endif

#endif
