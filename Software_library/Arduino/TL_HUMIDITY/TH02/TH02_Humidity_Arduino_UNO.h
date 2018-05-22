#ifndef TH02_HUMIDITY_ARDUINO_UNO_H
#define TH02_HUMIDITY_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "arduino_th02.h"

class TH02_Humidity_Arduino_UNO: public Sensor<double>{
private:
	TH02_dev& TH02Humi;
	int _read();
public:
	TH02_Humidity_Arduino_UNO();
};

extern TH02_Humidity_Arduino_UNO TL_Humidity;

#endif
