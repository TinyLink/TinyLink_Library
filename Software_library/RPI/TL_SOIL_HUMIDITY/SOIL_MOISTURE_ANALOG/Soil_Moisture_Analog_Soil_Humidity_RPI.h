#ifndef SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_RPI_H
#define SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_RPI_H

#include "Sensor_template.h"

namespace tinylink {
    class Soil_Moisture_Analog_Soil_Humidity : public Sensor<double>
    {
    private:
        int _pin = -1;
    
    protected:
        int _read();

    public:
        Soil_Moisture_Analog_Soil_Humidity(int pin);
    };
}

#if TINYLINK_SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
	extern tinylink::Soil_Moisture_Analog_Soil_Humidity TL_Soil_Humidity;
#endif
#endif
