#include "DHT22_Humidity_RPI.h"
#include "TL_Config.h"
#include "grovepi.h"
#include <cmath>

namespace tinylink {
	DHT22_HUMIDITY::DHT22_HUMIDITY(int pin): Sensor(0.0), _pin(pin), _tem(.0){
	    if (init_dev() == -1) exit(-1);
	}	
	
	int DHT22_HUMIDITY::_read(){
		pair<float, float> result = dht(_pin, 1);
		_tem = result.first; 
		if(!isnan(result.second)){
			_data = result.second;	
		}
		return 0;
	}
}
#if TINYLINK_HUMIDITY == DHT22
	tinylink::DHT22_HUMIDITY TL_Humidity(HUMIDITY_DIGITAL_OUTPUT);
#endif
