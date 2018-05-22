#ifndef DHT_22_HUMIDITY_ARDUINO_UNO_H
#define DHT_22_HUMIDITY_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "arduino_dht.h"

class DHT22_Humidity_Arduino_UNO: public Sensor<double>{
private:
	DHT_Lib& DHT22Humi;
	int _read();
public:
	DHT22_Humidity_Arduino_UNO();
};

extern DHT22_Humidity_Arduino_UNO TL_Humidity;

#endif
