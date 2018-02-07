#ifndef ONE_LED_LED_LINKIT_ONE_H
#define ONE_LED_LED_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"

class One_LED_LED_LinkIt_One{
private:
	int stateSig;
	const static int ledPin = 13;
public:
	One_LED_LED_LinkIt_One();
	void toggle();
	void turnOn();
	void turnOff();
	const int state();
};

extern One_LED_LED_LinkIt_One TL_LED;

#endif
