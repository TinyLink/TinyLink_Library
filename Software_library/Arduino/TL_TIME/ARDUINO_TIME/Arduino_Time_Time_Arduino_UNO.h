#ifndef ARDUINO_TIME_TIME_ARDUINO_UNO_h
#define ARDUINO_TIME_TIME_ARDUINO_UNO_h

#include <Arduino.h>

class Arduino_Time_Time_Arduino_UNO {
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

extern Arduino_Time_Time_Arduino_UNO TL_Time;

#endif
