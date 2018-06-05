#ifndef SOIL_HUMIDITY_SOIL_HUMIDITY_RPI_H
#define SOIL_HUMIDITY_SOIL_HUMIDITY_RPI_H

#include "Sensor_template.h"

namespace tinylink {
    class Soil_Humidity_Soil_Humidity_RPI : public Sensor<double>
    {
    private:
        int _pin = -1;
    
    protected:
        int _read();

    public:
        Soil_Humidity_Soil_Humidity_RPI(int pin);
    };
}

#if TINYLINK_SOIL_HUMIDITY == SOIL_HUMIDITY
	extern tinylink::Soil_Humidity_Soil_Humidity_RPI TL_Soil_Humidity;
#endif
#endif
