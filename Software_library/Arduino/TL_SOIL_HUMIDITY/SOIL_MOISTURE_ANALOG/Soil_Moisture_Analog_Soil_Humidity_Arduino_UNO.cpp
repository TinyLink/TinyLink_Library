#include "Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO.h"

Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO::Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO():Sensor(0.0){
}

int Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO::_read(){
	double soil_humidity = (double)analogRead(SOIL_HUMIDITY_ANALOG);
	if(soil_humidity>=0){
		_data = soil_humidity;
		return 0;
	}else{
		return -1;
	}
}

Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO TL_Soil_Humidity;
