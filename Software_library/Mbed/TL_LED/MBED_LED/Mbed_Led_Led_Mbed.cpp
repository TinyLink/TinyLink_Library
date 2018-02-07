#include <stdio.h>
#include <stdlib.h>
#include "Mbed_Led_Led_Mbed.h"

void Mbed_Led_Led::turnOff(){
	led = 1;
	stateSig = 0;
}
void Mbed_Led_Led::turnOn(){
	led = 0;
	stateSig = 1;        
}
void Mbed_Led_Led::toggle(){
	led = !led;
	stateSig = !stateSig;
}
int Mbed_Led_Led::state(){
	return stateSig;
}

Mbed_Led_Led TL_LED;
