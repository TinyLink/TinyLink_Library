#ifndef DHT11_HUMIDITY_RPI_H
#define DHT11_HUMIDITY_RPI_H

#include "Sensor_template.h"

namespace tinylink {

	class DHT11_HUMIDITY: public Sensor<double>
	{
	private:
		int _pin;
		double _tem;

	protected:
		int _read();
	
	public:
	    DHT11_HUMIDITY(int pin);
	};

}
#if TINYLINK_HUMIDITY == DHT11
	extern tinylink::DHT11_HUMIDITY TL_Humidity;
#endif
#endif

