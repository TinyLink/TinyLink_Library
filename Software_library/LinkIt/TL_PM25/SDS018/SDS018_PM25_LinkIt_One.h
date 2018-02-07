#ifndef SDS018_PM25_LINKIT_ONE_H
#define SDS018_PM25_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"

class SDS018_PM25_LinkIt_One: public Sensor<double>{
private:
	int start;
	double pm25, pm10;
	int _read();
public:
	SDS018_PM25_LinkIt_One();
};

extern SDS018_PM25_LinkIt_One TL_PM25;

#endif
