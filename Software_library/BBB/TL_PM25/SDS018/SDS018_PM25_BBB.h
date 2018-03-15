#ifndef SDS018_PM25_BBB_H
#define SDS018_PM25_BBB_H

#ifndef SDS018_PM25_Serial
#define SDS018_PM25_Serial TL_Serial
#endif

#include "UART.h"
#include <iostream>
#include <cstdio>
#include <pthread.h>
#include "Sensor_template.h"

#include "TL_Config.h"


using namespace std;

class SDS018_PM25 : public Sensor<double>
{
private:
 	double pm10;

protected:
	int _read();
  
public:
	SDS018_PM25();
};

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_PM25 == SDS018
		extern SDS018_PM25 TL_PM25;
	#endif
#endif


#endif
