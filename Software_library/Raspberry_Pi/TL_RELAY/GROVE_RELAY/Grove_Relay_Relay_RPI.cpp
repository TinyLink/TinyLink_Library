#include "Grove_Relay_Relay_RPI.h"
#include "TL_Config.h"
#include "grovepi.h"

namespace tinylink {

	Grove_Relay_RPI::Grove_Relay_RPI(int pin){
		
		if(init_dev() == -1){
			exit(-1);
		}
		_pin = pin;
		pinMode(_pin, OUTPUT);
    		digitalWrite(_pin, LOW);
	}

	void Grove_Relay_RPI::turnOn(){

		digitalWrite(_pin, HIGH);
        }

	void Grove_Relay_RPI::turnOff(){

		digitalWrite(_pin, LOW);
	}
}

tinylink::Grove_Relay_RPI TL_Relay(RELAY_DIGITAL_INPUT);
