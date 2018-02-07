#include "Grove_IMU9_Gyro_Arduino_UNO.h"

Grove_IMU9_Gyro_Arduino_UNO::Grove_IMU9_Gyro_Arduino_UNO():accelgyro(),I2C_M(),status(0),gx(0),gy(0),gz(0),state(0){
}

int Grove_IMU9_Gyro_Arduino_UNO::read(){
	if (state == 0){
		Wire.begin();
		accelgyro.initialize();
		if(accelgyro.testConnection()){
			status = 1;
		}else{
			status = 0;
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

double Grove_IMU9_Gyro_Arduino_UNO::data_x(){
	return (double) gx * 250 / 32768;
}

double Grove_IMU9_Gyro_Arduino_UNO::data_y(){
	return (double) gy * 250 / 32768;
}

double Grove_IMU9_Gyro_Arduino_UNO::data_z(){
	return (double) gz * 250 / 32768;
}

Grove_IMU9_Gyro_Arduino_UNO TL_Gyro;
