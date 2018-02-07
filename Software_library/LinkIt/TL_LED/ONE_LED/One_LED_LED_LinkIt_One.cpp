#include "One_LED_LED_LinkIt_One.h"

One_LED_LED_LinkIt_One::One_LED_LED_LinkIt_One():stateSig(0){
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
	stateSig = 0;
}

void One_LED_LED_LinkIt_One::toggle(){
	pinMode(ledPin, OUTPUT);
	if (stateSig == 0){
		digitalWrite(ledPin, HIGH);
		stateSig = 1;
	}else{
		digitalWrite(ledPin, LOW);
		stateSig = 0;
	}
}

void One_LED_LED_LinkIt_One::turnOn(){
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, HIGH);
	stateSig = 1;
}

void One_LED_LED_LinkIt_One::turnOff(){
	pinMode(ledPin, OUTPUT);
	digitalWrite(ledPin, LOW);
	stateSig = 0;
}

const int One_LED_LED_LinkIt_One::state(){
	return stateSig;
}

One_LED_LED_LinkIt_One TL_LED;
