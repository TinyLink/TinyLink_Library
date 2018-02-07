#ifndef LINKIT_OME_DHT_H
#define LINKIT_OME_DHT_H
#if ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

/* DHT library 
*	MIT license
*	written by Adafruit Industries
*/

#define MAXTIMINGS 85

#define DHT11_SENSOR 11
#define DHT22_SENSOR 22
#define DHT21_SENSOR 21
#define AM2301_SENSOR 21

class DHT_Lib {
private:
	uint8_t data[6];
	uint8_t _pin, _type, _count;
	unsigned long _lastreadtime;
	boolean firstreading;
	DHT_Lib(uint8_t pin, uint8_t type, uint8_t count=13);
	DHT_Lib(const DHT_Lib&);
	DHT_Lib& operator= (const DHT_Lib&);
public:
	static DHT_Lib& getSingleItem(uint8_t pin, uint8_t type);
	float readTemperature(bool S=false);
	float convertCtoF(float);
	float convertFtoC(float);
	float computeHeatIndex(float tempFahrenheit, float percentHumidity);
	float readHumidity(void);
	boolean read(void);
};
#endif
