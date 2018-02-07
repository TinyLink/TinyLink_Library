#ifndef GROVE_IMU9_GYRO_LINKIT_ONE_H
#define GROVE_IMU9_GYRO_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Wire.h"
#include "MPU9250.h"
#include "I2Cdev.h"


class Grove_IMU9_Gyro_LinkIt_One{
private:
	MPU9250 accelgyro;
	I2Cdev   I2C_M;
	int status;
	int16_t gx, gy, gz;
	int state;
public:
	Grove_IMU9_Gyro_LinkIt_One();
	int read();
	void init();
	double data_x();
	double data_y();
	double data_z();
};

extern Grove_IMU9_Gyro_LinkIt_One TL_Gyro;

#endif
