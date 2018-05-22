#include "DHT22_Humidity_LinkIt_One.h"

DHT22_Humidity_LinkIt_One::DHT22_Humidity_LinkIt_One():Sensor(0.0), DHT22Humi(DHT_Lib::getSingleItem(HUMIDITY_DIGITAL_OUTPUT,DHT22_SENSOR)){
}

int DHT22_Humidity_LinkIt_One::_read(){
	double chk = (double)DHT22Humi.readHumidity();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

DHT22_Humidity_LinkIt_One TL_Humidity;
