#include "Grove_IMU9_Magnet_LinkIt_One.h"

Grove_9DOF_Magnet::Grove_9DOF_Magnet(){
	state = 0;
}

int Grove_9DOF_Magnet::read(){
	if (state == 0){
		Wire.begin();
		magnet.initialize();
		if(magnet.testConnection()){
			status = 1;
		}else{
			status = 1;
		}
		state = 1;
	}
	if(status == 1){
		uint8_t devAddr = MPU9250_DEFAULT_ADDRESS;
		uint8_t buffer[14];
		I2C_M.writeByte(devAddr, MPU9250_RA_INT_PIN_CFG, 0x02);
		delay(10);
		I2C_M.writeByte(MPU9150_RA_MAG_ADDRESS, 0x0A, 0x01);
		delay(10);
		I2C_M.readBytes(MPU9150_RA_MAG_ADDRESS, MPU9150_RA_MAG_XOUT_L, 6, buffer);
		mx = (((int16_t)buffer[1]) << 8) | buffer[0];
		my = (((int16_t)buffer[3]) << 8) | buffer[2];
		mz = (((int16_t)buffer[5]) << 8) | buffer[4];
		return 0;
	}else{
		return -1;	
	}
}

double Grove_9DOF_Magnet::data_x(){
	return (double) mx * 4800 / 8192;
}

double Grove_9DOF_Magnet::data_y(){
	return (double) my * 4800 / 8192;
}

double Grove_9DOF_Magnet::data_z(){
	return (double) mz * 4800 / 8192;
}


#if MAGNET == GROVE_IMU9
	Grove_9DOF_Magnet TL_Magnet;
#endif
