#include "Grove_Digital_Light_Light_RPI.h"

Grove_Digital_Light_Light_RPI::Grove_Digital_Light_Light_RPI():Sensor(0.0), sig(0){
}

int Grove_Digital_Light_Light_RPI::_read(){
	if(!sig){
		sig = 1;
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
	Grove_Digital_Light_Light_RPI TL_Light;
#endif
