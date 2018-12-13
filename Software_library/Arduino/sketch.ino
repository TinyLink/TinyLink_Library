#include "TL_Libraries.h"
void setup(){
	TL_Serial.begin(9600);
}

void loop(){
	TL_Light.read();
	TL_Serial.println(TL_Light.data());
	TL_Time.delayMillis(1000);
}