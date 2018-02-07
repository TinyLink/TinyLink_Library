#ifndef SDS018_PM25_ARDUINO_UNO_H
#define SDS018_PM25_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include <SoftwareSerial.h>

class SDS018_PM25_Arduino_UNO: public Sensor<double>{
private:
	int start;
	double pm25, pm10;
	int _read();
public:
	SDS018_PM25_Arduino_UNO();
};

extern SDS018_PM25_Arduino_UNO TL_PM25;

#endif
