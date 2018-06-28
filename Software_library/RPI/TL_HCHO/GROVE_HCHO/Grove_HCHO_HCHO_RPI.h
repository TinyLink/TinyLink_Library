#ifndef GROVE_HCHO_HCHO_RPI_H
#define GROVE_HCHO_HCHO_RPI_H


#include "grovepi.h"
#include "Sensor_template.h"


class Grove_HCHO_HCHO_RPI: public Sensor<double>{
private:
	int _pin;
	double R0;
	int _read();
public:
	Grove_HCHO_HCHO_RPI(int pin);
};

#if TINYLINK_HCHO == GROVE_HCHO
	extern Grove_HCHO_HCHO_RPI TL_HCHO;
#endif

#endif
