#ifndef GROVE_TEMPERATURE_TEMPERATURE_RPI_H
#define GROVE_TEMPERATURE_TEMPERATURE_RPI_H

#include <Arduino.h>
#include <math.h>
#include "TL_Config.h"
#include "Sensor_template.h"


namespace tinylink{
	class Grove_Temperature_Temperature_RPI: public Sensor<double>{	
	private:
		int pin;
		int _read();
	public:
		Grove_Temperature_Temperature_RPI(int pin);
	};
}
#if TINYLINK_TEMPERATURE == GROVE_TEMPERATURE
	extern tinylink::Grove_Temperature_Temperature_RPI TL_Temperature;
#endif
#endif

