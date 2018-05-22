#ifndef TH02_TEMPERATURE_ARDUINO_UNO_H
#define TH02_TEMPERATURE_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "arduino_th02.h"

class TH02_Temperature_Arduino_UNO: public Sensor<double>{
private:
	TH02_dev& TH02Temp;
	int _read();
public:
	TH02_Temperature_Arduino_UNO();
};

extern TH02_Temperature_Arduino_UNO TL_Temperature;

#endif
