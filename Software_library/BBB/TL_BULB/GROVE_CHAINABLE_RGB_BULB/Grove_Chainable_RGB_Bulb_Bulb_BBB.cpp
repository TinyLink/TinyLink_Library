#include <Arduino.h>
#include "ChainableLED.h"
#include "TL_Config.h"
#include "Grove_Chainable_RGB_Bulb_Bulb_BBB.h"
#include "CommonDefines.h"
#include "GPIO.h"
#include "OVERLAY.h"

Grove_Chainable_RGB_Bulb_Bulb_BBB::Grove_Chainable_RGB_Bulb_Bulb_BBB():stateSig(0),led(1){
	led.init();
}
void Grove_Chainable_RGB_Bulb_Bulb_BBB::turnOn(){
	led.setColorRGB(0, 255, 255, 255);
	stateSig = 1;
}

void Grove_Chainable_RGB_Bulb_Bulb_BBB::turnOff(){
	led.setColorRGB(0, 0, 0, 0);
	stateSig = 0;
}

const int Grove_Chainable_RGB_Bulb_Bulb_BBB::state(){
	return stateSig;
}
#if TINYLINK_BULB == GROVE_CHAINABLE_RGB_BULB
	Grove_Chainable_RGB_Bulb_Bulb_BBB TL_Bulb;
#endif
