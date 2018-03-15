#include <Arduino.h>
#include <Wire.h>
#include "TL_Config.h"
#include "Grove_LCD_RGB_Display_Arduino_UNO.h"

Grove_LCD_RGB_Display_Arduino_UNO::Grove_LCD_RGB_Display_Arduino_UNO():lcd(), init(0){
}

void Grove_LCD_RGB_Display_Arduino_UNO::show(const char* data){
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

void Grove_LCD_RGB_Display_Arduino_UNO::show(const String& data){
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

void Grove_LCD_RGB_Display_Arduino_UNO::clear(){
	if(init == 0){
		lcd.begin(16, 2);
		//lcd.setRGB(255, 0, 0);
		lcd.clear();
		delay(500);
		init = 1;
	}
	lcd.clear();
}

const char* Grove_LCD_RGB_Display_Arduino_UNO::state(){
	return stateSig;
}

char Grove_LCD_RGB_Display_Arduino_UNO::stateSig[17] = "";

Grove_LCD_RGB_Display_Arduino_UNO TL_Display;
