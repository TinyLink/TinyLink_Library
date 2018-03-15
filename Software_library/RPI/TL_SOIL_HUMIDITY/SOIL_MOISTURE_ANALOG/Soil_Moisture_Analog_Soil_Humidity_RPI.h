#ifndef TL_SOIL_HUMIDITY
#define TL_SOIL_HUMIDITY

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


extern tinylink::Soil_Moisture_Analog_Soil_Humidity TL_Soil_Humidity;
#endif
