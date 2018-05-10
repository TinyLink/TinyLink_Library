#include "grovepi.h"
#include "Grove_LED_LED_RPI.h"

namespace tinylink {
	Grove_LED_LED_RPI::Grove_LED_LED_RPI():stateSig(0) {
		if (init_dev() == -1)
			exit(-1);
		pinMode(LED_DIGITAL_OUTPUT, OUTPUT);
	}
	void Grove_LED_LED_RPI::turnOn(void) {
		digitalWrite(LED_DIGITAL_OUTPUT, HIGH);
		stateSig = 1;
	}
	void Grove_LED_LED_RPI::turnOff(void) {
		digitalWrite(LED_DIGITAL_OUTPUT,LOW);
		stateSig = 0;
	}
	void Grove_LED_LED_RPI::toggle(void) {
		if (stateSig == 0){
			digitalWrite(LED_DIGITAL_OUTPUT, HIGH);
			stateSig = 1;
		}else{
			digitalWrite(LED_DIGITAL_OUTPUT, LOW);
			stateSig = 0;
		}        
	}
	const int Grove_LED_LED_RPI::state(void){
		return stateSig;
	}
}

tinylink::Grove_LED_LED_RPI TL_LED;
