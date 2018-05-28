#ifndef GROVE_DIGITAL_LIGHT_LIGHT_LINKIT_ONE_H
#define GROVE_DIGITAL_LIGHT_LIGHT_LINKIT_ONE_H

#include <Arduino.h>
#include <Wire.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_digital_light.h"

class Grove_Digital_Light_Light_LinkIt_One: public Sensor<double>{
private:
	int _read();
	int sig;
	TSL2561_CalculateLux TSL2561;
public:
	Grove_Digital_Light_Light_LinkIt_One();
};

extern Grove_Digital_Light_Light_LinkIt_One TL_Light;

#endif
