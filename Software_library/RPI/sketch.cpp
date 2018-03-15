#include "Arduino.h"
#include <string.h>

char* ch_result;

void setup() {

//	TL_Display.connect();
//	TL_Display.setRGB(0, 128, 64);
}

void loop() {
	
	TL_Display.show("I am listening");

	ch_result = TL_Voice.recognize(5);
        printf("%s\n", ch_result);
        if(strstr(ch_result, "ON")) {

		TL_Display.show("LIGHT ON");
                TL_Relay.turnOn();
        }
        else if (strstr(ch_result, "OFF")) {

		TL_Display.show("LIGHT OFF");
                TL_Relay.turnOff();
        }
	else
	{
		TL_Display.show("NOTHING!");
	}
	
	TL_Time.delayMillis(3000);	
}
