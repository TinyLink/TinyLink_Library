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

class INLED{ 
private: 
    string path; 
    int number; 
    virtual void writeINLED(string filename, string value); // write values to corresponding file
    virtual void removeTrigger(); 
public: 
    INLED(int number); 
    virtual void turnOn(); 
    virtual void turnOff(); 
    virtual void toggle();
    virtual void flash(uint32_t ms = 50); 
    virtual void outputState(); 
    virtual ~INLED(); 
};

#if PLATFORM == 3 && BOARD == 1005
# if LED == BBB_LED
extern INLED TL_LED;
extern INLED TL_LED1;
extern INLED TL_LED2;
extern INLED TL_LED3;
#endif
#endif

#endif