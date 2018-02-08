#include "Grove_Light_Light_RPI.h"
#include "TL_Config.h"

namespace tinylink {
	Grove_Light_RPI::Grove_Light_RPI(int pin): Sensor(0.0), _pin(pin){
		if (init_dev() == -1) exit(-1);
	}
	int Grove_Light_RPI::_read() {
        _data = (double)analogRead(_pin);
        return 0;
	}
}

tinylink::Grove_Light_RPI TL_Light(LIGHT_ANALOG);
