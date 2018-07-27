#include "Grove_Moisture_Soil_Humidity_BBB.h"


namespace tinylink {
	Grove_Moisture_Soil_Humidity_BBB::Grove_Moisture_Soil_Humidity_BBB(adcPin pin):Sensor(0.0) {
		_pin=pin;
	}
	int Grove_Moisture_Soil_Humidity_BBB::_read() {
		_data = (double)analogRead(_pin);
		return 0;
	}

}

#if TINYLINK_SOIL_HUMIDITY == GROVE_MOISTURE
	tinylink::Grove_Moisture_Soil_Humidity_BBB TL_Soil_Humidity(SOIL_HUMIDITY_ANALOG);
#endif
