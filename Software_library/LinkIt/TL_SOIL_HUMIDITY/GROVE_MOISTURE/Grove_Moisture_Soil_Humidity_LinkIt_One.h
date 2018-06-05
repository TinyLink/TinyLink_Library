#ifndef GROVE_MOISTURE_SOIL_HUMIDITY_LINKIT_ONE_H
#define GROVE_MOISTURE_SOIL_HUMIDITY_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_Moisture_Soil_Humidity_LinkIt_One: public Sensor<double>{
private:
	int _read();
public:
	Grove_Moisture_Soil_Humidity_LinkIt_One();
};

extern Grove_Moisture_Soil_Humidity_LinkIt_One TL_Soil_Humidity;

#endif
