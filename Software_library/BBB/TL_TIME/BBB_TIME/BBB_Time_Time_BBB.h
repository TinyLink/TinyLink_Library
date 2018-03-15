#ifndef BBB_TIME_TIME_BBB_H
#define BBB_TIME_TIME_BBB_H

#include "CLOCK.h"
#include <iostream>


class BBB_Time_Time_BBB {
public:
	void delayMillis(uint32_t duration);
	void delayMicros(uint32_t duration);
	uint32_t millis();
	uint32_t micros();	
	uint32_t millisFromStart();
	uint32_t microsFromStart();	

/*	string timeFromInternet();
	string timeFromGPS();*/
};

extern BBB_Time_Time_BBB TL_Time;

#endif
