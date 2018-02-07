#ifndef ARDUINO_TIME_TIME_ARDUINO_UNO_h
#define ARDUINO_TIME_TIME_ARDUINO_UNO_h

#include <Arduino.h>

class Time {
public:
	void delayMillis(int millis) {
		delay(millis);
	}
	void delayMicros(int micros) {
		delayMicroseconds(micros);
	}
	unsigned long millisFromStart(){
		return millis();
	}
	unsigned long microsFromStart(){
		return micros();
	}
};

extern Time TL_Time;

#endif
