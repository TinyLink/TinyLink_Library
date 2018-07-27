#include "Grove_Temperature_Temperature_BBB.h"


namespace tinylink {
	Grove_Temperature_Temperature_BBB::Grove_Temperature_Temperature_BBB(adcPin p):Sensor(0.0){
	pin = p;
	}

	int Grove_Temperature_Temperature_BBB::_read(){
		double a = (double)analogRead(pin);
		double resistance = (double)(1023 - a) * 10000 / a;
		_data = (double)(1 / (log(resistance / 10000) / 4250 + 1 / 298.15) - 273.15);
		return 0;
	}
}
#if TINYLINK_TEMPERATURE == GROVE_TEMPERATURE
	tinylink::Grove_Temperature_Temperature_BBB TL_Temperature(TEMPERATURE_ANALOG);
#endif
