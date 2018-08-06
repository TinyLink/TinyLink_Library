#include "Grove_IMU9_Magnet_BBB.h"


Grove_9DOF_Magnet_BBB::Grove_9DOF_Magnet_BBB():magnet(),status(0),mx(0),my(0),mz(0){
		magnet.initialize();		
		if(magnet.testConnection()){
			magnet.initMagnet();
			status = 1;
		}else{
			status = 0;
		}	
}

int Grove_9DOF_Magnet_BBB::read(){
	
	if(status == 1){
		mx = magnet.getMagnetionX();
		my = magnet.getMagnetionY();
		mz = magnet.getMagnetionZ();
		return 0;
	}else{
		return -1;	
	}
}

double Grove_9DOF_Magnet_BBB::data_x(){
	return (double) mx * 4800 / 8192;
}

double Grove_9DOF_Magnet_BBB::data_y(){
	return (double) my * 4800 / 8192;
}

double Grove_9DOF_Magnet_BBB::data_z(){
	return (double) mz * 4800 / 8192;
}
#if TINYLINK_MAGNET == GROVE_IMU9
	Grove_9DOF_Magnet_BBB TL_Magnet;
#endif
