#ifndef GROVE_DIGITAL_LIGHT_LIGHT_ARDUINO_UNO_H
#define GROVE_DIGITAL_LIGHT_LIGHT_ARDUINO_UNO_H

#include <Arduino.h>
#include <Wire.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "arduino_digital_light.h"

class Grove_Digital_Light_Light_Arduino_UNO: public Sensor<double>{
private:
	int sig;
	int _read();
	TSL2561_CalculateLux TSL2561;
public:
	Grove_Digital_Light_Light_Arduino_UNO();
};

extern Grove_Digital_Light_Light_Arduino_UNO TL_Light;

#endif
