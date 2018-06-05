#ifndef GROVE_MOISTURE_SOIL_HUMIDITY_ARDUINO_UNO_H
#define GROVE_MOISTURE_SOIL_HUMIDITY_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_Moisture_Soil_Humidity_Arduino_UNO: public Sensor<double>{
private:
	int _read();
public:
	Grove_Moisture_Soil_Humidity_Arduino_UNO();
};

extern Grove_Moisture_Soil_Humidity_Arduino_UNO TL_Soil_Humidity;

#endif
