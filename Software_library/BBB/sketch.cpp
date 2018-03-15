#include "Arduino.h"

void setup() {
}

void loop() {
	TL_Temperature.read();
	TL_Time.delayMillis(1000);
	cout<<TL_Temperature.data()<<endl;
	TL_Time.delayMillis(1000);
}
