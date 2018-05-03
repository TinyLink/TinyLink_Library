#include <Arduino.h>
#include "ChainableLED.h"
#include "TL_Config.h"
#include "Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO.h"

Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO::Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO():stateSig(0),led(BULB_DIGITAL_OUTPUT, BULB_DIGITAL_INPUT, 1){
	led.init();
}
void Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO::turnOn(){
	led.setColorRGB(0, 255, 255, 255);
	stateSig = 1;
}

void Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO::turnOff(){
	led.setColorRGB(0, 0, 0, 0);
	stateSig = 0;
}

const int Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO::state(){
	return stateSig;
}

Grove_Chainable_RGB_Bulb_Bulb_Arduino_UNO TL_Bulb;
