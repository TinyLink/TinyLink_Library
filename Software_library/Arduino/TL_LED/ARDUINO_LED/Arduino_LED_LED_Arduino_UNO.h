#ifndef ARDUINO_LED_LED_ARDUINO_UNO_H
#define ARDUINO_LED_LED_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"

class Arduino_LED_LED_Arduino_UNO
{

private:
	int stateSig;
	const static int ledPin = 13;

public:
	Arduino_LED_LED_Arduino_UNO();
	void toggle();
	void turnOn();
	void turnOff();
	const int state();		// 0 for OFF, 1 for ON
};

extern Arduino_LED_LED_Arduino_UNO TL_LED;

#endif
