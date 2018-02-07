#ifndef MBED_TIME_TIME_MBED_H
#define MBED_TIME_TIME_MBED_H

#include <stdio.h>
#include <stdlib.h>
#include "mbed.h"
#include "TL_Config.h"

class Mbed_Time_Time_Mbed{
public:
	Mbed_Time_Time_Mbed(){}
	void delayMillis(unsigned long ms);
	void delayMicros(unsigned long us);
	unsigned long millisFromStart();
	unsigned long microsFromStart();		
};

extern Mbed_Time_Time_Mbed TL_Time;

#endif
