#include "Grove_Moisture_Soil_Humidity_LinkIt_One.h"

Grove_Moisture_Soil_Humidity_LinkIt_One::Grove_Moisture_Soil_Humidity_LinkIt_One():Sensor(0.0){
}

int Grove_Moisture_Soil_Humidity_LinkIt_One::_read(){
	double soil_humidity = (double)analogRead(SOIL_HUMIDITY_ANALOG);
	if(soil_humidity>=0){
		_data = soil_humidity;
		return 0;
	}else{
		return -1;
	}
}

Grove_Moisture_Soil_Humidity_LinkIt_One TL_Soil_Humidity;
