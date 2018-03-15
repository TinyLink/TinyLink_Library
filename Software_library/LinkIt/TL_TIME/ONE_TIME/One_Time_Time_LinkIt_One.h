#ifndef ONE_TIME_TIME_LINKIT_ONE_H
#define ONE_TIME_TIME_LINKIT_ONE_H

#include <Arduino.h>

class One_Time_Time_LinkIt_One {
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

extern One_Time_Time_LinkIt_One TL_Time;

#endif
