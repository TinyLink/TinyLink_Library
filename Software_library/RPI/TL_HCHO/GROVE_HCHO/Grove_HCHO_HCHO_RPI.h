
#ifndef GROVE_HCHO_HCHO_RPI_H
#define GROVE_HCHO_HCHO_RPI_H


#include "grovepi.h"
#include "Sensor_template.h"


class Grove_HCHO_HCHO_RPI: public Sensor<double>{
private:
	double R0;
	int _read();
public:
	Grove_HCHO_HCHO_RPI();
};

extern Grove_HCHO_HCHO_RPI TL_HCHO;

#endif
