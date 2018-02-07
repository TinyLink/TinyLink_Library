#include "Grove_IMU9_Gyro_LinkIt_One.h"

Grove_IMU9_Gyro_LinkIt_One::Grove_IMU9_Gyro_LinkIt_One():accelgyro(), I2C_M(), status(0), gx(0), gy(9), gz(0), state(0){
}

int Grove_IMU9_Gyro_LinkIt_One::read(){
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
		gx = accelgyro.getRotationX();
		gy = accelgyro.getRotationY();
		gz = accelgyro.getRotationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_IMU9_Gyro_LinkIt_One::data_x(){
	return (double) gx * 250 / 32768;
}

double Grove_IMU9_Gyro_LinkIt_One::data_y(){
	return (double) gy * 250 / 32768;
}

double Grove_IMU9_Gyro_LinkIt_One::data_z(){
	return (double) gz * 250 / 32768;
}

Grove_IMU9_Gyro_LinkIt_One TL_Gyro;
