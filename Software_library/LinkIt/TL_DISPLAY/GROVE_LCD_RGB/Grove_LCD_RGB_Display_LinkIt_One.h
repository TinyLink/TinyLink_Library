#ifndef GROVE_LCD_RGB_DISPLAY_LINKIT_ONE_H
#define GROVE_LCD_RGB_DISPLAY_LINKIT_ONE_H

#include "rgb_lcd.h"

class Grove_LCD_RGB_Display_LinkIt_One{
private:
	int init;
	static char stateSig[17];
	rgb_lcd lcd;
public:
	Grove_LCD_RGB_Display_LinkIt_One();
	void show(const char* data);
	void show(const String& data);
	void clear();
	const char* state();
};

extern Grove_LCD_RGB_Display_LinkIt_One TL_Display;

#endif
