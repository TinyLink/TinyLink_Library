#include "Grove_IMU9_Accelerometer_LinkIt_One.h"

Grove_IMU9_Accelerometer_LinkIt_One::Grove_IMU9_Accelerometer_LinkIt_One():accelgyro(), I2C_M(), status(0), ax(0), ay(0), az(0), state(0){
}

int Grove_IMU9_Accelerometer_LinkIt_One::read(){
	if (state == 0){
		Wire.begin();
		accelgyro.initialize();
		if(accelgyro.testConnection()){
			status = 1;
		}else{
			status = 1;
		}
		state = 1;
	}
	if(status == 1){
		ax = accelgyro.getAccelerationX();
		ay = accelgyro.getAccelerationY();
		az = accelgyro.getAccelerationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_IMU9_Accelerometer_LinkIt_One::data_x(){
	return (double) ax / 16384;
}

double Grove_IMU9_Accelerometer_LinkIt_One::data_y(){
	return (double) ay / 16384;
}

double Grove_IMU9_Accelerometer_LinkIt_One::data_z(){
	return (double) az / 16384;
}

Grove_IMU9_Accelerometer_LinkIt_One TL_Accelerometer;
