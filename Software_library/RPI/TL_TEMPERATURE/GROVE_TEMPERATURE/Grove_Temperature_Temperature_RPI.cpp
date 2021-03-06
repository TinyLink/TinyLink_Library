#include "Grove_Temperature_Temperature_RPI.h"


namespace tinylink {
	Grove_Temperature_Temperature_RPI::Grove_Temperature_Temperature_RPI(int p):Sensor(0.0),pin(p){
	if (init_dev() == -1) exit(-1);
	}

	int Grove_Temperature_Temperature_RPI::_read(){
		double a = (double)analogRead(pin);
		double resistance = (double)(1023 - a) * 10000 / a;
		_data = (double)(1 / (log(resistance / 10000) / 4250 + 1 / 298.15) - 273.15);
		return 0;
	}
}
#if TINYLINK_TEMPERATURE == GROVE_TEMPERATURE
	tinylink::Grove_Temperature_Temperature_RPI TL_Temperature(TEMPERATURE_ANALOG);
#endif
