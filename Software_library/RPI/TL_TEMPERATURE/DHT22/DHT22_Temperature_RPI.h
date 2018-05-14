#ifndef DHT22_TEMPERATURE_RPI_H
#define DHT22_TEMPERATURE_RPI_H

#include "Sensor_template.h"

namespace tinylink {
	class DHT22_TEMPERATURE: public Sensor<double>{
	private:
		int _pin;
		int _hum;

	protected:
		int _read();

	public:
	    DHT22_TEMPERATURE(int pin);
	};
}
#if TINYLINK_TEMPERATURE == DHT22
	extern tinylink::DHT22_TEMPERATURE TL_Temperature;
#endif
#endif

