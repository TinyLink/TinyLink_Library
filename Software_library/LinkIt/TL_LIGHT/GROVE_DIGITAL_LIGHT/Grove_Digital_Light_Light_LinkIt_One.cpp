#include "Grove_Digital_Light_Light_LinkIt_One.h"

Grove_Digital_Light_Light_LinkIt_One::Grove_Digital_Light_Light_LinkIt_One():Sensor(0.0), sig(0){
}

int Grove_Digital_Light_Light_LinkIt_One::_read(){
	if(!sig){
		Wire.begin();
		TSL2561.init();
		sig = 1;
	}
	double intensity = TSL2561.readVisibleLux();
	if(intensity>=0){
		_data = intensity;
		return 0;
	}else{
		return -1;
	}
}

Grove_Digital_Light_Light_LinkIt_One TL_Light;
