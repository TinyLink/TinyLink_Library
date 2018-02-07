#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Time_Time_Mbed.h"

void Mbed_Time_Time_Mbed::delayMillis(unsigned long ms){
	wait_ms(ms);
}

void Mbed_Time_Time_Mbed::delayMicros(unsigned long us){
	wait_us(us);
}

unsigned long Mbed_Time_Time_Mbed::millisFromStart(){
	Timer T;
	T.start();
	unsigned long t = T.read_ms();
	T.stop();
	return t;
}
unsigned long Mbed_Time_Time_Mbed::microsFromStart(){
	Timer T; 
	T.start();
	unsigned long t = T.read_us();
	T.stop();
	return t;
}

Mbed_Time_Time_Mbed TL_Time;
