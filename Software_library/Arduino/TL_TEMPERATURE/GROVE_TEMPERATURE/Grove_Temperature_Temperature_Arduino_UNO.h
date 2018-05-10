#ifndef GROVE_TEMPERATURE_TEMPERATURE_ARDUINO_UNO_H
#define GROVE_TEMPERATURE_TEMPERATURE_ARDUINO_UNO_H

#include <Arduino.h>
#include <math.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_Temperature_Temperature_Arduino_UNO: public Sensor<double>{
private:
	int _read();
public:
	Grove_Temperature_Temperature_Arduino_UNO();
};

extern Grove_Temperature_Temperature_Arduino_UNO TL_Temperature;

#endif
