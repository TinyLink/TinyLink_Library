#include "DHT22_Temperature_RPI.h"
#include "TL_Config.h"
#include "grovepi.h"
#include <cmath>

namespace tinylink {
	DHT22_TEMPERATURE::DHT22_TEMPERATURE(int pin): Sensor(0.0), _pin(pin), _hum(.0){  
	    if (init_dev() == -1) exit(-1);
	}	
	int DHT22_TEMPERATURE::_read(){
		pair<float, float> result = dht(_pin, 1);
		if(!isnan(result.first)){
			_data = result.first;
		}
		_hum = result.second;
		return 0;
	}
}

#if TINYLINK_TEMPERATURE == DHT22
	tinylink::DHT22_TEMPERATURE TL_Temperature(TEMPERATURE_DIGITAL_OUTPUT);
#endif
