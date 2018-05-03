#ifndef MBED_LED_LED_MBED_H
#define MBED_LED_LED_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

class Mbed_Led_Led{
private:
	int stateSig;
	DigitalOut led;
public:
	Mbed_Led_Led():led(p21){
	}
	void turnOff();
	void turnOn();
	void toggle();
	int state();
};

extern  Mbed_Led_Led TL_LED;

#endif
