#ifndef DHT_22_HUMIDITY_LINKIT_ONE_H
#define DHT_22_HUMIDITY_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_dht.h"

class DHT22_Humidity_LinkIt_One: public Sensor<double>{
private:
	DHT_Lib& DHT22Humi;
	int _read();
public:
	DHT22_Humidity_LinkIt_One();
};


extern DHT22_Humidity_LinkIt_One TL_Humidity;

#endif
