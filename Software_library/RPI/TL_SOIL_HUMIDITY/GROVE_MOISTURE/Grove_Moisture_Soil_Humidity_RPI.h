#ifndef GROVE_MOISTURE_SOIL_HUMIDITY_RPI_H
#define GROVE_MOISTURE_SOIL_HUMIDITY_RPI_H

#include "Sensor_template.h"

namespace tinylink {
    class Grove_Moisture_Soil_Humidity_RPI : public Sensor<double>
    {
    private:
        int _pin = -1;
    
    protected:
        int _read();

    public:
        Grove_Moisture_Soil_Humidity_RPI(int pin);
    };
}

#if TINYLINK_SOIL_HUMIDITY == GROVE_MOISTURE
	extern tinylink::Grove_Moisture_Soil_Humidity_RPI TL_Soil_Humidity;
#endif
#endif
