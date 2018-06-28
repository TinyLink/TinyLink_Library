#ifndef TINYLINK_LIGHT_H
#define TINYLINK_LIGHT_H

#include "grovepi.h"
#include "Sensor_template.h"
#include <cstdlib>

namespace tinylink {
    class Grove_Light_RPI: public Sensor<double>
    {
    private:
        int _pin;
    protected:
        int _read();
    public:
        Grove_Light_RPI(int pin);
    };
}

#if TINYLINK_LIGHT == GROVE_LIGHT
	extern tinylink::Grove_Light_RPI TL_Light;
#endif

#endif
