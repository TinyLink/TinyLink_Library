#include "Soil_Moisture_Analog_Soil_Humidity_BBB.h"

Soil_Moisture_Analog::Soil_Moisture_Analog(adcPin pin):Sensor(0.0) {
	Soil_Moisture_Analog_Pin = pin;
}

int Soil_Moisture_Analog::_read() {
	_data = (double)analogRead(Soil_Moisture_Analog_Pin);
	return 1;
}

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
		Soil_Moisture_Analog TL_Soil_Humidity(SOIL_HUMIDITY_ANALOG);
	#endif
#endif
