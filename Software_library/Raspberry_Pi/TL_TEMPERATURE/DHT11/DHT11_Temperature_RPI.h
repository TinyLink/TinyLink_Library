#ifndef DHT11_TEMPERATURE_RPI_H
#define DHT11_TEMPERATURE_RPI_H

#include "Sensor_template.h"

namespace tinylink {
	class DHT11_TEMPERATURE: public Sensor<double>
	{
	private:
		int _pin;
		int _hum;

	protected:
		int _read();

	public:
	    DHT11_TEMPERATURE(int pin);
	};
}

extern tinylink::DHT11_TEMPERATURE TL_Temperature;

#endif

