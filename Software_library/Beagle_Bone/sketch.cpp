#include "Arduino.h"

void setup() {
}

void loop() {
	TL_LED.toggle();
	TL_Time.delayMillis(1000);
}
