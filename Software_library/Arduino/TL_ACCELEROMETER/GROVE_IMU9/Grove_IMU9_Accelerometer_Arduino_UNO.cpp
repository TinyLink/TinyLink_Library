#include "Grove_IMU9_Accelerometer_Arduino_UNO.h"

Grove_IMU9_Accelerometer_Arduino_UNO::Grove_IMU9_Accelerometer_Arduino_UNO():accelgyro(),I2C_M(),status(0),ax(0),ay(0),az(0),state(0){
}

int Grove_IMU9_Accelerometer_Arduino_UNO::read(){
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
		ax = accelgyro.getAccelerationX();
		ay = accelgyro.getAccelerationY();
		az = accelgyro.getAccelerationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_IMU9_Accelerometer_Arduino_UNO::data_x(){
	return (double) ax / 16384;
}

double Grove_IMU9_Accelerometer_Arduino_UNO::data_y(){
	return (double) ay / 16384;
}

double Grove_IMU9_Accelerometer_Arduino_UNO::data_z(){
	return (double) az / 16384;
}

Grove_IMU9_Accelerometer_Arduino_UNO TL_Accelerometer;
