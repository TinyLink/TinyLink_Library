#ifndef GROVE_TEMPERATURE_TEMPERATURE_LINKIT_ONE_H
#define GROVE_TEMPERATURE_TEMPERATURE_LINKIT_ONE_H

#include <Arduino.h>
#include <math.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class Grove_Temperature_Temperature_LinkIt_One: public Sensor<double>{
private:
	int _read();
public:
	Grove_Temperature_Temperature_LinkIt_One();
};

extern Grove_Temperature_Temperature_LinkIt_One TL_Temperature;

#endif
