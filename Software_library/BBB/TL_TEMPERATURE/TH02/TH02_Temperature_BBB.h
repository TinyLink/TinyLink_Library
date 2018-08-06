#ifndef TH02_TEMPERATURE_BBB_H
#define TH02_TEMPERATURE_BBB_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "BBB_th02.h"

class TH02_Temperature_BBB: public Sensor<double>{
private:
	TH02_dev& TH02Temp;
	int _read();
public:
	TH02_Temperature_BBB();
};

extern TH02_Temperature_BBB TL_Temperature;

#endif
