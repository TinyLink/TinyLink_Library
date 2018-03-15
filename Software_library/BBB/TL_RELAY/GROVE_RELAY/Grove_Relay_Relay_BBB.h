#ifndef GROVE_RELAY_RELAY_BBB_H
#define GROVE_RELAY_RELAY_BBB_H

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdio>
#include "CommonDefines.h"
#include "GPIO.h"
#include "OVERLAY.h"
#include "TL_Config.h"

class Grove_Relay_Relay_BBB{
private:
	int stateSig;
public:
	Grove_Relay_Relay_BBB();
	void turnOn();
	void turnOff();
	void toggle();
	const int state();
};
#if TINYLINK_RELAY == GROVE_RELAY
	extern Grove_Relay_Relay_BBB TL_Relay;
#endif

#endif
