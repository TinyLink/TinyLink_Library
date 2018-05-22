#ifndef TH02_TEMPERATURE_LINKIT_ONE_H
#define TH02_TEMPERATURE_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_th02.h"

class TH02_Temperature_LinkIt_One: public Sensor<double>{
private:
	TH02_dev TH02Temp;
	int sig;
	int _read();
public:
	TH02_Temperature_LinkIt_One();
};

extern TH02_Temperature_LinkIt_One TL_Temperature;

#endif
