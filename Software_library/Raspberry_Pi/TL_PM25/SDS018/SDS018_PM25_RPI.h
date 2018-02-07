#ifndef SDS018_PM25_RPI_H
#define SDS018_PM25_RPI_H

#include <iostream>
#include <cstdio>
#include <pthread.h>
#include "Sensor_template.h"
#include "TL_Config.h"
using namespace std;

namespace tinylink {
	class SDS018_PM25 : public Sensor<double>
	{
	private:
	 	double pm10;	

	protected:
		int _read();
	  
	public:
		SDS018_PM25();
	};
}


extern tinylink::SDS018_PM25 TL_PM25;



#endif