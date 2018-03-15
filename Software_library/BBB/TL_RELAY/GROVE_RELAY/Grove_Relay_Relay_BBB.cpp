#include "Grove_Relay_Relay_BBB.h"

Grove_Relay_Relay_BBB::Grove_Relay_Relay_BBB():stateSig(0){
	pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
}

void Grove_Relay_Relay_BBB::turnOn(){
	pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
	digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
	stateSig = 1;
}

void Grove_Relay_Relay_BBB::turnOff(){
	pinMode(RELAY_DIGITAL_OUTPUT, OUTPUT);
	digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
	stateSig = 0;
}

void Grove_Relay_Relay_BBB::toggle(){
	if(stateSig == 0){
		digitalWrite(RELAY_DIGITAL_OUTPUT, HIGH);
		stateSig = 1;
	}else{
		digitalWrite(RELAY_DIGITAL_OUTPUT, LOW);
		stateSig = 0;
	}
}

const int Grove_Relay_Relay_BBB::state(){
	return stateSig;
}

#if TINYLINK_RELAY == GROVE_RELAY
	Grove_Relay_Relay_BBB TL_Relay;
#endif
