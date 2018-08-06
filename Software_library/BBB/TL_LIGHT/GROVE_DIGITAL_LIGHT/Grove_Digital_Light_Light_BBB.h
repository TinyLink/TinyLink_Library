#ifndef GROVE_DIGITAL_LIGHT_LIGHT_BBB_H
#define GROVE_DIGITAL_LIGHT_LIGHT_BBB_H

#include <Arduino.h>
#include <Wire.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "BBB_digital_light.h"

class Grove_Digital_Light_Light_BBB: public Sensor<double>{
private:
	int sig;
	int _read();
	TSL2561_CalculateLux TSL2561;
public:
	Grove_Digital_Light_Light_BBB();
};
#if TINYLINK_LIGHT == GROVE_DIGITAL_LIGHT
	extern Grove_Digital_Light_Light_BBB TL_Light;
#endif

#endif
