#ifndef GROVE_LCD_RGB_DISPLAY_BBB_H
#define GROVE_LCD_RGB_DISPLAY_BBB_H

#include "rgb_lcd.h"

class Grove_LCD_RGB_Display_BBB{
private:
	int init;
	static char stateSig[17];
	rgb_lcd lcd;
public:
	Grove_LCD_RGB_Display_BBB();
	void show(const char* data);
	void show(const String& data);
	void clear();
	const char* state();
};

extern Grove_LCD_RGB_Display_BBB TL_Display;

#endif
