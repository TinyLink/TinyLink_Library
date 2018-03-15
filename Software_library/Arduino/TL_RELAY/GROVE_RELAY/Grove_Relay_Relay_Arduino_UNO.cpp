#include <Arduino.h>
#include "TL_Config.h"
#include "Grove_Relay_Relay_Arduino_UNO.h"

Grove_Relay_Relay_Arduino_UNO::Grove_Relay_Relay_Arduino_UNO():stateSig(0){
	pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
}

void Grove_Relay_Relay_Arduino_UNO::turnOn(){
	digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
	stateSig = 1;
}

void Grove_Relay_Relay_Arduino_UNO::turnOff(){
	digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
	stateSig = 0;
}

void Grove_Relay_Relay_Arduino_UNO::toggle(){
	if(stateSig == 0){
		digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
		stateSig = 1;
	}else{
		digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
		stateSig = 0;
	}
}

const int Grove_Relay_Relay_Arduino_UNO::state(){
	return stateSig;
}

Grove_Relay_Relay_Arduino_UNO TL_Relay;
