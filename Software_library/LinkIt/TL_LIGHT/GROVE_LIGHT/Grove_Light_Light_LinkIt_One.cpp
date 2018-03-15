#include "Grove_Light_Light_LinkIt_One.h"

Grove_Light_Light_LinkIt_One::Grove_Light_Light_LinkIt_One():Sensor(0.0){
}

int Grove_Light_Light_LinkIt_One::_read(){
	double intensity = (double)analogRead(LIGHT_ANALOG);
	if(intensity>=0){
		_data = intensity;
		return 0;
	}else{
		return -1;
	}
}

Grove_Light_Light_LinkIt_One TL_Light;
