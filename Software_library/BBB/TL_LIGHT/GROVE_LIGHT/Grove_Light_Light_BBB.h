#ifndef GROVE_LIGHT_LIGHT_BBB_H
#define GROVE_LIGHT_LIGHT_BBB_H

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include <pthread.h>

#include "ADC.h"
#include "Sensor_template.h"
#include "TL_Config.h"
using namespace std;

class Grove_Light_BBB : public Sensor<double>
{
private:
	adcPin Grove_Light_Pin;

protected:
	int _read();

public:
	Grove_Light_BBB(adcPin pin);
};


#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_LIGHT == GROVE_LIGHT
		extern Grove_Light_BBB TL_Light;
	#endif
#endif


#endif


