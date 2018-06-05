#include "Grove_Moisture_Soil_Humidity_Arduino_UNO.h"

Grove_Moisture_Soil_Humidity_Arduino_UNO::Grove_Moisture_Soil_Humidity_Arduino_UNO():Sensor(0.0){
}

int Grove_Moisture_Soil_Humidity_Arduino_UNO::_read(){
	double soil_humidity = (double)analogRead(SOIL_HUMIDITY_ANALOG);
	if(soil_humidity>=0){
		_data = soil_humidity;
		return 0;
	}else{
		return -1;
	}
}

Grove_Moisture_Soil_Humidity_Arduino_UNO TL_Soil_Humidity;
