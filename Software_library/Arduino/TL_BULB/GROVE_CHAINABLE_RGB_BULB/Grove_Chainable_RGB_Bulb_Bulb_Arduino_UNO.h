#ifndef GROVE_CHAINABLE_RGB_BULB_BULB_ARDUINO_UNO_H
#define GROVE_CHAINABLE_RGB_BULB_BULB_ARDUINO_UNO_H

#include "ChainableLED.h"

class Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO{
private:
	ChainableLED led;
	int stateSig;
public:
	Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO();
	void turnOn();
	void turnOff();
	void toggle();
	const int state();
};

extern Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO TL_Bulb;

#endif
