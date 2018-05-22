#ifndef LINKIT_ONE_DHT_CPP
#define LINKIT_ONE_DHT_CPP
#include "linkit_one_dht.h"

DHT_Lib::DHT_Lib(uint8_t pin, uint8_t type, uint8_t count):_pin(pin), _type(type), _count(count), firstreading(true), _lastreadtime(0){
	pinMode(_pin, INPUT);
	digitalWrite(_pin, HIGH);
}

DHT_Lib& DHT_Lib::getSingleItem(uint8_t pin, uint8_t type){
	static DHT_Lib singleton(pin, type);
	return singleton;
}

float DHT_Lib::readTemperature(bool S) {
	float f;
	if (read()) {
		switch (_type) {
			case DHT11_SENSOR:{
				f = data[2];
				if(S)
					f = convertCtoF(f);
				return f;
			}
			case DHT22_SENSOR:
			case DHT21_SENSOR:{
				f = data[2] & 0x7F;
				f *= 256;
				f += data[3];
				f /= 10;
				if (data[2] & 0x80)
					f *= -1;
				if(S)
					f = convertCtoF(f);
			}
			return f;
		}
	}
	return NAN;
}

float DHT_Lib::convertCtoF(float c) {
	return c * 9 / 5 + 32;
}

float DHT_Lib::convertFtoC(float f) {
	return (f - 32) * 5 / 9; 
}

float DHT_Lib::readHumidity(void) {
	float f;
	if (read()) {
		switch (_type) {
			case DHT11_SENSOR:{
				f = data[0];
				return f;
			}
			case DHT22_SENSOR:
			case DHT21_SENSOR:{
				f = data[0];
				f *= 256;
				f += data[1];
				f /= 10;
				return f;
			}
		}
	}
	return NAN;
}

float DHT_Lib::computeHeatIndex(float tempFahrenheit, float percentHumidity) {
	return -42.379 + 2.04901523 * tempFahrenheit + 10.14333127 * percentHumidity + -0.22475541 * tempFahrenheit*percentHumidity + -0.00683783 * pow(tempFahrenheit, 2) + -0.05481717 * pow(percentHumidity, 2) + 0.00122874 * pow(tempFahrenheit, 2) * percentHumidity + 0.00085282 * tempFahrenheit*pow(percentHumidity, 2) +-0.00000199 * pow(tempFahrenheit, 2) * pow(percentHumidity, 2);
}


boolean DHT_Lib::read(void) {
	uint8_t laststate = HIGH;
	uint8_t counter = 0;
	uint8_t j = 0, i;
	unsigned long currenttime;
	currenttime = millis();
	if (currenttime < _lastreadtime) {
		_lastreadtime = 0;
	}
	if (!firstreading && ((currenttime - _lastreadtime) < 2000)) {
		return true; // return last correct measurement
	}
	firstreading = false;
	_lastreadtime = millis();
	data[0] = data[1] = data[2] = data[3] = data[4] = 0;
	digitalWrite(_pin, HIGH);
	delay(250);
	pinMode(_pin, OUTPUT);
	digitalWrite(_pin, LOW);
	delay(20);
	noInterrupts();
	digitalWrite(_pin, HIGH);
	delayMicroseconds(40);
	pinMode(_pin, INPUT);
	for ( i=0; i< MAXTIMINGS; i++) {
		counter = 0;
		while (digitalRead(_pin) == laststate) {
			counter++;
			delayMicroseconds(1);
			if (counter == 255) {
				break;
			}
		}
		laststate = digitalRead(_pin);
		if (counter == 255) break;
		if ((i >= 4) && (i%2 == 0)) {
			data[j/8] <<= 1;
			if (counter > _count)
				data[j/8] |= 1;
			j++;
		}
	}
	interrupts();
	if ((j >= 40) && (data[4] == ((data[0] + data[1] + data[2] + data[3]) & 0xFF)) ) {
		return true;
	}
	return false;
}
#endif
