#ifndef GROVE_IMU9_GYRO_RPI_H
#define GROVE_IMU9_GYRO_RPI_H

#include "TL_Config.h"
#include "MPU9250_RPI.h"



class Grove_IMU9_Gyro_RPI{
private:
	MPU9250 accelgyro;
	int status;
	int16_t gx, gy, gz;

public:
	Grove_IMU9_Gyro_RPI();
	int read();		
	void init();
	double data_x();
	double data_y();
	double data_z();
};

#if TINYLINK_GYRO == GROVE_IMU9
	extern Grove_IMU9_Gyro_RPI TL_Gyro;
#endif

#endif
