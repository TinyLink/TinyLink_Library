#include <Arduino.h>
#include <Wire.h>
#include "TL_Config.h"
#include "Grove_LCD_RGB_Display_Arduino_Uno.h"

Grove_LCD_RGB_Display_Arduino_Uno::Grove_LCD_RGB_Display_Arduino_Uno():lcd(), init(0){
}

void Grove_LCD_RGB_Display_Arduino_Uno::show(const char* data){
	if(init == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.clear();
		delay(500);
		init = 1;
	}
	strncpy(stateSig, data, 16);
	lcd.clear();
	lcd.print(stateSig);
}

void Grove_LCD_RGB_Display_Arduino_Uno::show(const String& data){
	if(init == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.clear();
		delay(500);
		init = 1;
	}
	strncpy(stateSig, data.c_str(), 16);
	lcd.clear();
	lcd.print(stateSig);
}

void Grove_LCD_RGB_Display_Arduino_Uno::clear(){
	if(init == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.clear();
		delay(500);
		init = 1;
	}
	lcd.clear();
}

const char* Grove_LCD_RGB_Display_Arduino_Uno::state(){
	return stateSig;
}

char Grove_LCD_RGB_Display_Arduino_Uno::stateSig[17] = "";

Grove_LCD_RGB_Display_Arduino_Uno TL_Display;
