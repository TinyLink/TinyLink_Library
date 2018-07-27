#ifndef GROVE_TEMPERATURE_TEMPERATURE_BBB_H
#define GROVE_TEMPERATURE_TEMPERATURE_BBB_H

#include <math.h>
#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include <pthread.h>

#include "ADC.h"
#include "Sensor_template.h"
#include "TL_Config.h"

namespace tinylink{
	class Grove_Temperature_Temperature_BBB: public Sensor<double>{	
	private:
		adcPin pin;
		int _read();
	public:
		Grove_Temperature_Temperature_BBB(adcPin pin);
	};
}
#if TINYLINK_TEMPERATURE == GROVE_TEMPERATURE
	extern tinylink::Grove_Temperature_Temperature_BBB TL_Temperature;
#endif
#endif

