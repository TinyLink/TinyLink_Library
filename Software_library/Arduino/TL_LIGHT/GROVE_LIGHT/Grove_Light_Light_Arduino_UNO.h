#ifndef GROVE_LIGHT_LIGHT_ARDUINO_UNO_H
#define GROVE_LIGHT_LIGHT_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_Light_Light_Arduino_UNO: public Sensor<double>{
private:
	int _read();
public:
	Grove_Light_Light_Arduino_UNO();
};

extern Grove_Light_Light_Arduino_UNO TL_Light;

#endif
