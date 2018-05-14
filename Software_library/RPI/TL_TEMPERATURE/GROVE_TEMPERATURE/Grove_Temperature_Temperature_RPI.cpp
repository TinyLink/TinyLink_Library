#include "Grove_Temperature_Temperature_RPI.h"


namespace tinylink {
	Grove_Temperature_Temperature_RPI::Grove_Temperature_Temperature_RPI():Sensor(0.0){
	if (init_dev() == -1) exit(-1);
	}

	int Grove_Temperature_Temperature_RPI::_read(){
		double a = (double)analogRead(TEMPERATURE_ANALOG);
		double resistance = (double)(1023 - a) * 10000 / a;
		_data = (double)(1 / (log(resistance / 10000) / 4250 + 1 / 298.15) - 273.15);
		return 0;
	}
}
tinylink::Grove_Temperature_Temperature_RPI TL_Temperature;
