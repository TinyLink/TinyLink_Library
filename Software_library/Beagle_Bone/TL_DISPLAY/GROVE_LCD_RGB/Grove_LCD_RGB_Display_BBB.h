#ifndef GROVE_LCD_RGB_DISPLAY_BBB_H
#define GROVE_LCD_RGB_DISPLAY_BBB_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
//#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>

#include "grovepi.h"
#include "WString.h"

namespace tinylink
{
  class Grove_Display_RPI
  {
          public:

                  Grove_Display_RPI();
                  void connect();

                  void setRGB(uint8_t red, uint8_t green, uint8_t blue);
                  void show(const char *str);
		  void show(const String& str);
		  void clear();

          private:

                  void sendCommand(uint8_t mode, uint8_t command);
                  void selectSlave(uint8_t slave);

                  uint8_t DEVICE_FILE;
                  bool connected;

                  static uint8_t DISPLAY_RGB_ADDR;
                  static uint8_t DISPLAY_TEXT_ADDR;

                  static uint8_t CLEAR_DISPLAY;
                  static uint8_t DISPLAY_ON;
                  static uint8_t NO_CURSOR;
                  static uint8_t ENABLE_2ROWS;
                  static uint8_t PROGRAM_MODE;
                  static uint8_t NEW_ROW;
                  static uint8_t DISPLAY_CHAR;
                  static uint8_t MAX_NO_CHARS;
  };
}

extern tinylink::Grove_Display_RPI TL_Display;

#endif

