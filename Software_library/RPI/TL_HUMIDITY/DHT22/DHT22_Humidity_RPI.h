#ifndef DHT22_HUMIDITY_RPI_H
#define DHT22_HUMIDITY_RPI_H

#include "Sensor_template.h"

namespace tinylink {

	class DHT22_HUMIDITY: public Sensor<double>
	{
	private:
		int _pin;
		double _tem;

	protected:
		int _read();
	
	public:
	    DHT22_HUMIDITY(int pin);
	};

}
#if TINYLINK_HUMIDITY == DHT22
	extern tinylink::DHT22_HUMIDITY TL_Humidity;
#endif

#endif

