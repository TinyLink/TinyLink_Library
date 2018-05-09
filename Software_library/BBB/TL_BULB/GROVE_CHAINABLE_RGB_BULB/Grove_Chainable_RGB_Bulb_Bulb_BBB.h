#ifndef GROVE_CHAINABLE_RGB_BULB_BULB_BBB_H
#define GROVE_CHAINABLE_RGB_BULB_BULB_BBB_H

#include "ChainableLED.h"

class Grove_Chainable_RGB_Bulb_Bulb_BBB{
private:
	ChainableLED led;
	int stateSig;
public:
	Grove_Chainable_RGB_Bulb_Bulb_BBB();
	void turnOn();
	void turnOff();
	const int state();
};
#if TINYLINK_BULB == GROVE_CHAINABLE_RGB_BULB
	extern Grove_Chainable_RGB_Bulb_Bulb_BBB TL_Bulb;
#endif

#endif
