#include <cassert>
#include "Soil_Moisture_Analog_Soil_Humidity_RPI.h"
#include "grovepi.h"
#include "TL_Config.h"

namespace tinylink {
	Soil_Moisture_Analog_Soil_Humidity::Soil_Moisture_Analog_Soil_Humidity(int pin):Sensor(0.0), _pin(pin) {
	    if (init_dev() == -1) exit(1);
	}
	int Soil_Moisture_Analog_Soil_Humidity::_read() {
		_data = (double)analogRead(_pin);
		return 0;
	}

}

tinylink::Soil_Moisture_Analog_Soil_Humidity TL_Soil_Humidity(SOIL_HUMIDITY_ANALOG);
