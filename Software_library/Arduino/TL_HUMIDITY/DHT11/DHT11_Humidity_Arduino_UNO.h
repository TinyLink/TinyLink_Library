#ifndef DHT_11_HUMIDITY_ARDUINO_UNO_H
#define DHT_11_HUMIDITY_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "arduino_dht.h"

class DHT11_Humidity_Arduino_UNO: public Sensor<double>{
private:
	DHT_Lib& DHT11Humi;
	int _read();
public:
	DHT11_Humidity_Arduino_UNO();
};

extern DHT11_Humidity_Arduino_UNO TL_Humidity;

#endif
