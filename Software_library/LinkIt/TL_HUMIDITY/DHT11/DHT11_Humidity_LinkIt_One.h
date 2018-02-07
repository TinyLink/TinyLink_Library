#ifndef DHT_11_HUMIDITY_LINKIT_ONE_H
#define DHT_11_HUMIDITY_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_dht.h"

class DHT11_Humidity_LinkIt_One: public Sensor<double>{
private:
	DHT_Lib& DHT11Humi;
	int _read();
public:
	DHT11_Humidity_LinkIt_One();
};


extern DHT11_Humidity_LinkIt_One TL_Humidity;

#endif
