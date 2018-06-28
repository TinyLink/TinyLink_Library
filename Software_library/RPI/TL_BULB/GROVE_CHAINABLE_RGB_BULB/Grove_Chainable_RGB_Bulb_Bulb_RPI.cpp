#include "ChainableLED.h"
#include "grovepi.h"
#include "TL_Config.h"
#include "Grove_Chainable_RGB_Bulb_Bulb_RPI.h"

Grove_Chainable_RGB_Bulb_Bulb_RPI::Grove_Chainable_RGB_Bulb_Bulb_RPI():stateSig(0),led(1){
	if (init_dev() == -1) exit(1);
	led.init();
}
void Grove_Chainable_RGB_Bulb_Bulb_RPI::turnOn(){
	led.setColorRGB(0, 255, 255, 255);
	stateSig = 1;
}

void Grove_Chainable_RGB_Bulb_Bulb_RPI::turnOff(){
	led.setColorRGB(0, 0, 0, 0);
	stateSig = 0;
}

const int Grove_Chainable_RGB_Bulb_Bulb_RPI::state(){
	return stateSig;
}
#if TINYLINK_BULB == GROVE_CHAINABLE_RGB_BULB
	Grove_Chainable_RGB_Bulb_Bulb_RPI TL_Bulb;
#endif
