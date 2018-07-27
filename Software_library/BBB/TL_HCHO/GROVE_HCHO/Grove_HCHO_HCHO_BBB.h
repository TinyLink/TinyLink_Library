#ifndef GROVE_HCHO_HCHO_BBB_H
#define GROVE_HCHO_HCHO_BBB_H

#include <math.h>
#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include <pthread.h>

#include "ADC.h"
#include "Sensor_template.h"
#include "TL_Config.h"


class Grove_HCHO_HCHO_BBB: public Sensor<double>{
private:
	adcPin _pin;
	double R0;
	int _read();
public:
	Grove_HCHO_HCHO_BBB(adcPin pin);
};

#if TINYLINK_HCHO == GROVE_HCHO
	extern Grove_HCHO_HCHO_BBB TL_HCHO;
#endif

#endif
