#ifndef TH02_HUMIDITY_LINKIT_ONE_H
#define TH02_HUMIDITY_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_th02.h"

class TH02_Humidity_LinkIt_One: public Sensor<double>{
private:
	TH02_dev TH02Humi;
	int sig;
	int _read();
public:
	TH02_Humidity_LinkIt_One();
};

extern TH02_Humidity_LinkIt_One TL_Humidity;

#endif
