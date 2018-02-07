#include "DHT11_Temperature_RPI.h"
#include "TL_Config.h"
#include "grovepi.h"

namespace tinylink {
	DHT11_TEMPERATURE::DHT11_TEMPERATURE(int pin): Sensor(0.0), _pin(pin), _hum(.0){  
	    if (init_dev() == -1) exit(-1);
	}	
	
	int DHT11_TEMPERATURE::_read(){
		pair<float, float> result = dht(_pin);
	    _data = result.first; 
	    _hum = result.second;	
		return 0;
	}
}


tinylink::DHT11_TEMPERATURE TL_Temperature(TEMPERATURE_DIGITAL_OUTPUT);
