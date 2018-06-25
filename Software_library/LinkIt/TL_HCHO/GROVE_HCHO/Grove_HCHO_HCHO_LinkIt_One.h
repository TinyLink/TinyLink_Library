#ifndef GROVE_HCHO_HCHO_LINKIT_ONE_H
#define GROVE_HCHO_HCHO_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"


class Grove_HCHO_HCHO_LinkIt_One: public Sensor<double>{
private:
	double R0;
	int _read();
public:
	Grove_HCHO_HCHO_LinkIt_One();
};

extern Grove_HCHO_HCHO_LinkIt_One TL_HCHO;

#endif