#ifndef SD_SHIELD_ARDUINO_UNO_H
#define SD_SHIELD_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#include "File_Arduino.h"

#include <SPI.h>
#include <SD.h>

class SD_Card{
private:
	TL_File myFile;
public:
	SD_Card();
	bool begin();
	bool exists(String path);
	bool remove(String path);
	bool mkdir(String path);
	bool rmdir(String path);
	char* StoC(String s);
	TL_File open(String path, String mode = "r");
};

extern SD_Card TL_Storage;

#endif
