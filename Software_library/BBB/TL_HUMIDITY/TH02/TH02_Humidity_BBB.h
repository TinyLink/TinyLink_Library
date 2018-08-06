#ifndef TH02_HUMIDITY_BBB_H
#define TH02_HUMIDITY_BBB_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "BBB_th02.h"

class TH02_Humidity_BBB: public Sensor<double>{
private:
	TH02_dev& TH02Humi;
	int _read();
public:
	TH02_Humidity_BBB();
};

extern TH02_Humidity_BBB TL_Humidity;

#endif
