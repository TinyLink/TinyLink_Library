#ifndef GROVE_IMU9_MAGNET_BBB_H
#define GROVE_IMU9_MAGNET_BBB_H

#include "TL_Config.h"
#include "MPU9250_BBB.h"

class Grove_9DOF_Magnet_BBB{
private:
	MPU9250 magnet;
	int state;
	int status;
	int16_t mx, my, mz;
public:
	Grove_9DOF_Magnet_BBB();
	int read();
	double data_x();
	double data_y();
	double data_z();
};

#if TINYLINK_MAGNET == GROVE_IMU9
	extern Grove_9DOF_Magnet_BBB TL_Magnet;
#endif

#endif
