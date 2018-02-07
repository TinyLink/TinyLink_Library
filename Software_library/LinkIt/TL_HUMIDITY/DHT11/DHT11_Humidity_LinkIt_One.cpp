#include "DHT11_Humidity_LinkIt_One.h"

DHT11_Humidity_LinkIt_One::DHT11_Humidity_LinkIt_One():Sensor(0.0), DHT11Humi(DHT_Lib::getSingleItem(HUMIDITY_DIGITAL_OUTPUT,DHT11_SENSOR)){
}

int DHT11_Humidity_LinkIt_One::_read(){
	double chk = (double)DHT11Humi.readHumidity();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

DHT11_Humidity_LinkIt_One TL_Humidity;