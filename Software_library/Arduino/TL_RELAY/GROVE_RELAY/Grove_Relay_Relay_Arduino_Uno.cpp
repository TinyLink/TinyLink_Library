#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Relay_Relay_Arduino_Uno.h"

Grove_Relay_Relay_Arduino_Uno::Grove_Relay_Relay_Arduino_Uno():stateSig(0){
	pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
}

void Grove_Relay_Relay_Arduino_Uno::turnOn(){
	digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
	stateSig = 1;
}

void Grove_Relay_Relay_Arduino_Uno::turnOff(){
	digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
	stateSig = 0;
}

void Grove_Relay_Relay_Arduino_Uno::toggle(){
	if(stateSig == 0){
		digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
		stateSig = 1;
	}else{
		digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
		stateSig = 0;
	}
}

const int Grove_Relay_Relay_Arduino_Uno::state(){
	return stateSig;
}

Grove_Relay_Relay_Arduino_Uno TL_Relay;
