#ifndef SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_ARDUINO_UNO_H
#define SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO: public Sensor<double>{
private:
	int _read();
public:
	Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO();
};

extern Soil_Moisture_Analog_Soil_Humidity_Arduino_UNO TL_Soil_Humidity;

#endif
