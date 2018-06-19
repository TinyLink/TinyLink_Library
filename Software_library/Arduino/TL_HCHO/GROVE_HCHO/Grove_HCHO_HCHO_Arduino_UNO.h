#ifndef GROVE_HCHO_HCHO_ARDUINO_UNO_H
#define GROVE_HCHO_HCHO_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"


class Grove_HCHO_HCHO_Arduino_UNO: public Sensor<double>{
private:
	double R0;
	int _read();
public:
	Grove_HCHO_HCHO_Arduino_UNO();
};

extern Grove_HCHO_HCHO_Arduino_UNO TL_HCHO;

#endif