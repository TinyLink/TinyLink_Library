#ifndef BBB_LED_LED_BBB_H
#define BBB_LED_LED_BBB_H

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include "TL_Config.h"

using namespace std;

#define INLED_PATH "/sys/class/leds/beaglebone:green:usr"

class BBB_LED_LED_BBB{ 
private: 
    string path; 
    int number; 
    virtual void writeINLED(string filename, string value); // write values to corresponding file
    virtual void removeTrigger(); 
public: 
    BBB_LED_LED_BBB(int number); 
    virtual void turnOn(); 
    virtual void turnOff(); 
    virtual void toggle();
    virtual void flash(uint32_t ms = 50); 
    virtual void outputState();
    const int state();
    virtual ~BBB_LED_LED_BBB(); 
};

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_LED == BBB_LED
		extern BBB_LED_LED_BBB TL_LED;
		extern BBB_LED_LED_BBB TL_LED1;
		extern BBB_LED_LED_BBB TL_LED2;
		extern BBB_LED_LED_BBB TL_LED3;
	#endif
#endif

#endif
