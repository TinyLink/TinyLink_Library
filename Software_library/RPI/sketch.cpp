#include "Arduino.h"


void setup() {
}

void loop() {
	TL_Light.read();
	std::cout<<TL_Light.data()<<endl;
	TL_Time.delayMillis(1000);
}
