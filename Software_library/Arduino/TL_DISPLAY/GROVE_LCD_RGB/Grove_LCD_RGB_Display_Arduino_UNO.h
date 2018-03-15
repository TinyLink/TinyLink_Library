#ifndef GROVE_LCD_RGB_DISPLAY_ARDUINO_UNO.h
#define GROVE_LCD_RGB_DISPLAY_ARDUINO_UNO.h

#include "rgb_lcd.h"

class Grove_LCD_RGB_Display_Arduino_UNO{
private:
	int init;
	static char stateSig[17];
	rgb_lcd lcd;
public:
	Grove_LCD_RGB_Display_Arduino_UNO();
	void show(const char* data);
	void show(const String& data);
	void clear();
	const char* state();
};

extern Grove_LCD_RGB_Display_Arduino_UNO TL_Display;

#endif
