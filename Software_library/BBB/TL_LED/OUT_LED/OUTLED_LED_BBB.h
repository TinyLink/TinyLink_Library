#ifndef OUTLED_LED_BBB_H
#define OUTLED_LED_BBB_H

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include "CommonDefines.h"
#include "GPIO.h"
#include "OVERLAY.h"
#include "TL_Config.h"

using namespace std;


class OUT_LED { 
private: 
    Pin pin;
    bool status;
public: 
    OUT_LED(Pin pin); 
    virtual void turnOn(); 
    virtual void turnOff(); 
    virtual void toggle();
    virtual bool state();
};
#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_LED == OUTLED
		extern OUT_LED TL_LED;
	#endif
#endif

#endif
