#include "Arduino_LED_LED_Arduino_UNO.h"

Arduino_LED_LED_Arduino_UNO::Arduino_LED_LED_Arduino_UNO():stateSig(0){
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
	stateSig = 0;
}

void Arduino_LED_LED_Arduino_UNO::toggle(){
	if (stateSig == 0){
		digitalWrite(ledPin, HIGH);
		stateSig = 1;
	}else{
		digitalWrite(ledPin, LOW);
		stateSig = 0;
	}
}

void Arduino_LED_LED_Arduino_UNO::turnOn(){
	digitalWrite(ledPin, HIGH);
	stateSig = 1;
}

void Arduino_LED_LED_Arduino_UNO::turnOff(){
	digitalWrite(ledPin, LOW);
	stateSig = 0;
}

const int Arduino_LED_LED_Arduino_UNO::state(){
	return stateSig;
}

Arduino_LED_LED_Arduino_UNO TL_LED;
