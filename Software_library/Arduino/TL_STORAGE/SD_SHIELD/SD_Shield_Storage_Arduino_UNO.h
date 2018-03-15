#ifndef SD_SHIELD_ARDUINO_UNO_H
#define SD_SHIELD_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#ifdef TINYLINK_FILE
	#include "Arduino_File_File_Arduino_UNO.h"
#endif

#include <SPI.h>
#include <SD.h>

class SD_Shield_Storage_Arduino_UNO{
private:
#ifdef TINYLINK_FILE
	TL_File myFile;
#endif
public:
	SD_Shield_Storage_Arduino_UNO();
	bool begin();
	bool exists(String path);
	bool remove(String path);
	bool mkdir(String path);
	bool rmdir(String path);
	char* StoC(String s);
#ifdef TINYLINK_FILE
	TL_File open(String path, String mode = "r");
#endif
};

extern SD_Shield_Storage_Arduino_UNO TL_Storage;

#endif
