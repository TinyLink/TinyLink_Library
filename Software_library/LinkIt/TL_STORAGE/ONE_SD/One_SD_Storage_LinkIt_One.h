#ifndef ONE_SD_STORAGE_LINKIT_ONE_H
#define ONE_SD_STORAGE_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#include "File_LinkIt_One.h"

#include <LTask.h>
#include <LFlash.h>
#include <LSD.h>
#include <LStorage.h>

#define Drv LSD

class Internal_SD{
private:
	TL_File myFile;
public:
	Internal_SD();
	bool begin();
	bool exists(String path);
	bool remove(String path);
	bool mkdir(String path);
	bool rmdir(String path);
	char* StoC(String s);
	TL_File open(String path, String mode = "r");
};

extern Internal_SD TL_Storage;

#endif
