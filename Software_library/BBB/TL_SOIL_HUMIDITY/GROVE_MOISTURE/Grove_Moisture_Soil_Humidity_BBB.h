#ifndef GROVE_MOISTURE_SOIL_HUMIDITY_BBB_H
#define GROVE_MOISTURE_SOIL_HUMIDITY_BBB_H

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include <pthread.h>

#include "ADC.h"
#include "Sensor_template.h"
#include "TL_Config.h"

namespace tinylink {
    class Grove_Moisture_Soil_Humidity_BBB : public Sensor<double>
    {
    private:
        adcPin _pin;
    
    protected:
        int _read();

    public:
        Grove_Moisture_Soil_Humidity_BBB(adcPin pin);
    };
}

#if TINYLINK_SOIL_HUMIDITY == GROVE_MOISTURE
	extern tinylink::Grove_Moisture_Soil_Humidity_BBB TL_Soil_Humidity;
#endif
#endif
