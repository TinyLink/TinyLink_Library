#include "Grove_Light_Light_Arduino_UNO.h"

Grove_Light_Light_Arduino_UNO::Grove_Light_Light_Arduino_UNO():Sensor(0.0){
}

int Grove_Light_Light_Arduino_UNO::_read(){
	double intensity = (double)analogRead(LIGHT_ANALOG);
	if(intensity>=0){
		_data = intensity;
		return 0;
	}else{
		return -1;
	}
}

Grove_Light_Light_Arduino_UNO TL_Light;
