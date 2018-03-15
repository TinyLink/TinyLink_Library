#ifndef SDS018_PM10_BBB_H
#define SDS018_PM10_BBB_H

#ifndef SDS018_PM10_Serial
#define SDS018_PM10_Serial TL_Serial
#endif

#include "UART.h"
#include <iostream>
#include <cstdio>
#include <pthread.h>
#include "Sensor_template.h"

#include "TL_Config.h"


using namespace std;

class SDS018_PM10 : public Sensor<double>
{
private:
 	double pm25;

protected:
	int _read();
  
public:
	SDS018_PM10();
};


#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_PM10 == SDS018
		extern SDS018_PM10 TL_PM10;
	#endif
#endif


#endif
