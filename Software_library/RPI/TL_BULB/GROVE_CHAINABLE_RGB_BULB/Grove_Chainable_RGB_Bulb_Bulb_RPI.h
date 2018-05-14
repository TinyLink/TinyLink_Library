#ifndef GROVE_CHAINABLE_RGB_BULB_BULB_RPI_H
#define GROVE_CHAINABLE_RGB_BULB_BULB_RPI_H

#include "ChainableLED.h"

class Grove_Chainable_RGB_Bulb_Bulb_RPI{
private:
	ChainableLED led;
	int stateSig;
public:
	Grove_Chainable_RGB_Bulb_Bulb_RPI();
	void turnOn();
	void turnOff();
	const int state();
};
#if TINYLINK_BULB == GROVE_CHAINABLE_RGB_BULB
	extern Grove_Chainable_RGB_Bulb_Bulb_RPI TL_Bulb;
#endif

#endif
