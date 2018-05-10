#include "Grove_Temperature_Temperature_LinkIt_One.h"

Grove_Temperature_Temperature_LinkIt_One::Grove_Temperature_Temperature_LinkIt_One():Sensor(0.0){
}

int Grove_Temperature_Temperature_LinkIt_One::_read(){
	double intensity = (double)analogRead(TEMPERATURE_ANALOG);
	double R = 1023.0/intensity-1.0;
	_data = 1.0/(log(R)/4275+1/298.15)-273.15;
	return 0;
}

Grove_Temperature_Temperature_LinkIt_One TL_Temperature;
