#ifndef DHT_22_TEMPERATURE_LINKIT_ONE_H
#define DHT_22_TEMPERATURE_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "Sensor_template.h"
#include "linkit_one_dht.h"

class DHT22_Temperature_LinkIt_One: public Sensor<double>{
private:
	DHT_Lib& DHT22Temp;
	int _read();
public:
	DHT22_Temperature_LinkIt_One();
};

extern DHT22_Temperature_LinkIt_One TL_Temperature;

#endif
