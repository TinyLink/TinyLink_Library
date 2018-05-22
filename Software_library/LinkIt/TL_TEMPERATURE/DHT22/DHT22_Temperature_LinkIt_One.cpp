#include "DHT22_Temperature_LinkIt_One.h"

DHT22_Temperature_LinkIt_One::DHT22_Temperature_LinkIt_One():Sensor(0.0), DHT22Temp(DHT_Lib::getSingleItem(TEMPERATURE_DIGITAL_OUTPUT,DHT22_SENSOR)){
}

int DHT22_Temperature_LinkIt_One::_read(){
	double chk = (double)DHT22Temp.readTemperature();
	if (!isnan(chk)){
		_data = chk;
		return 0;
	}
	return -1;
}

DHT22_Temperature_LinkIt_One TL_Temperature;
