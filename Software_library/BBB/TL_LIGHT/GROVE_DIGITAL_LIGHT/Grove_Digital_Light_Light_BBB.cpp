#include "Grove_Digital_Light_Light_BBB.h"

Grove_Digital_Light_Light_BBB::Grove_Digital_Light_Light_BBB():Sensor(0.0), sig(0){
}

int Grove_Digital_Light_Light_BBB::_read(){
	if(!sig){
		sig = 1;
		Wire.begin();
		TSL2561.init();
	}
	double intensity = TSL2561.readVisibleLux();
	if(intensity>=0){
		_data = intensity;
		return 0;
	}else{
		return -1;
	}
}
#if TINYLINK_LIGHT == GROVE_DIGITAL_LIGHT
	Grove_Digital_Light_Light_BBB TL_Light;
#endif
