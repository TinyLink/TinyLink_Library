#ifndef GROVE_DIGITAL_LIGHT_LIGHT_RPI_H
#define GROVE_DIGITAL_LIGHT_LIGHT_RPI_H



#include "TL_Config.h"
#include "Sensor_template.h"
#include "RPI_digital_light.h"

class Grove_Digital_Light_Light_RPI: public Sensor<double>{
private:
	int sig;
	int _read();
	TSL2561_CalculateLux TSL2561;
public:
	Grove_Digital_Light_Light_RPI();
};

#if TINYLINK_LIGHT == GROVE_DIGITAL_LIGHT
	extern Grove_Digital_Light_Light_RPI TL_Light;
#endif

#endif
