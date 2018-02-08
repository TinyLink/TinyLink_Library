#include "DHT11_Humidity_RPI.h"
#include "TL_Config.h"
#include "grovepi.h"

namespace tinylink {
	DHT11_HUMIDITY::DHT11_HUMIDITY(int pin): Sensor(0.0), _pin(pin), _tem(.0){
	    if (init_dev() == -1) exit(-1);
	}	
	
	int DHT11_HUMIDITY::_read(){
		pair<float, float> result = dht(_pin);
	    _tem = result.first; 
	    _data = result.second;	
		return 0;
	}
}
tinylink::DHT11_HUMIDITY TL_Humidity(HUMIDITY_DIGITAL_OUTPUT);
