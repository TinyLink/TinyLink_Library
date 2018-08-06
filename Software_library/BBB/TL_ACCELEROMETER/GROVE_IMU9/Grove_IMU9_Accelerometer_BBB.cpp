#include "Grove_IMU9_Accelerometer_BBB.h"


Grove_IMU9_Accelerometer_BBB::Grove_IMU9_Accelerometer_BBB():accelgyro(),status(0),ax(0),ay(0),az(0){
	accelgyro.initialize();
	if(accelgyro.testConnection()){
		status = 1;
	}else{
		status = 0;
	}
}

int Grove_IMU9_Accelerometer_BBB::read(){
	if(status == 1){
		ax = accelgyro.getAccelerationX();
		ay = accelgyro.getAccelerationY();
		az = accelgyro.getAccelerationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_IMU9_Accelerometer_BBB::data_x(){
	return (double) ax / 16384;
}

double Grove_IMU9_Accelerometer_BBB::data_y(){
	return (double) ay / 16384;
}

double Grove_IMU9_Accelerometer_BBB::data_z(){
	return (double) az / 16384;
}

#if TINYLINK_ACCELEROMETER == GROVE_IMU9
	Grove_IMU9_Accelerometer_BBB TL_Accelerometer;
#endif
