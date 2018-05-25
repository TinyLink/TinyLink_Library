#include "Grove_Digital_Light_Light_Arduino_UNO.h"

Grove_Digital_Light_Light_Arduino_UNO::Grove_Digital_Light_Light_Arduino_UNO():Sensor(0.0), sig(0){
}

int Grove_Digital_Light_Light_Arduino_UNO::_read(){
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

Grove_Digital_Light_Light_Arduino_UNO TL_Light;
