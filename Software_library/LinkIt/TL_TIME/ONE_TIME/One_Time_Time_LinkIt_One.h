#ifndef TIME_LINKIT_ONE_H
#define TIME_LINKIT_ONE_H

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
