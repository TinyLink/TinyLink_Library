#include <cassert>
#include "Soil_Humidity_Soil_Humidity_RPI.h"
#include "grovepi.h"
#include "TL_Config.h"

namespace tinylink {
	Soil_Humidity_Soil_Humidity_RPI::Soil_Humidity_Soil_Humidity_RPI(int pin):Sensor(0.0), _pin(pin) {
	    if (init_dev() == -1) exit(1);
	}
	int Soil_Humidity_Soil_Humidity_RPI::_read() {
		_data = (double)analogRead(_pin);
		return 0;
	}

}

#if TINYLINK_SOIL_HUMIDITY == SOIL_HUMIDITY
tinylink::Soil_Humidity_Soil_Humidity_RPI TL_Soil_Humidity(SOIL_HUMIDITY_ANALOG);
#endif
