#include "Grove_IMU9_Gyro_BBB.h"

Grove_IMU9_Gyro_BBB::Grove_IMU9_Gyro_BBB():status(0),gx(0),gy(0),gz(0){ 
	accelgyro.initialize();
	if(accelgyro.testConnection()){
		status = 1;
	}else{
		status = 0;
	}
}

int Grove_IMU9_Gyro_BBB::read(){
	if(status == 1){
		gx = accelgyro.getRotationX();
		gy = accelgyro.getRotationY();
		gz = accelgyro.getRotationZ();
		return 0;
	}else{
		return -1;
	}
}

double Grove_IMU9_Gyro_BBB::data_x(){
	return (double) gx * 250 / 32768;
}

double Grove_IMU9_Gyro_BBB::data_y(){
	return (double) gy * 250 / 32768;
}

double Grove_IMU9_Gyro_BBB::data_z(){
	return (double) gz * 250 / 32768;
}

#if TINYLINK_GYRO == GROVE_IMU9
	Grove_IMU9_Gyro_BBB TL_Gyro;
#endif
