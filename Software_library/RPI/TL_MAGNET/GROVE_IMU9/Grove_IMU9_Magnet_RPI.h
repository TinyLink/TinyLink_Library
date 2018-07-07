#ifndef GROVE_IMU9_MAGNET_RPI_H
#define GROVE_IMU9_MAGNET_RPI_H

#include "TL_Config.h"
#include "MPU9250_RPI.h"

class Grove_9DOF_Magnet_RPI{
private:
	MPU9250 magnet;
	int state;
	int status;
	int16_t mx, my, mz;
public:
	Grove_9DOF_Magnet_RPI();
	int read();
	double data_x();
	double data_y();
	double data_z();
};

#if TINYLINK_MAGNET == GROVE_IMU9
	extern Grove_9DOF_Magnet_RPI TL_Magnet;
#endif

#endif
