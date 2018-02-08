#ifndef SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_BBB_H
#define SOIL_MOISTURE_ANALOG_SOIL_HUMIDITY_BBB_H

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

class Soil_Moisture_Analog : public Sensor<double>
{
private:
	adcPin Soil_Moisture_Analog_Pin;

protected:
	int _read();

public:
	Soil_Moisture_Analog(adcPin pin);
};


void* read_thread_Soil_Moisture_Analog(void* arg);


#if PLATFORM == 3 && BOARD == 1005
#if SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
extern Soil_Moisture_Analog TL_Soil_Humidity;
#endif
#endif


#endif


