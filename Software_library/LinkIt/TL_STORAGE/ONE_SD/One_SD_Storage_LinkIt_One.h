#ifndef ONE_SD_STORAGE_LINKIT_ONE_H
#define ONE_SD_STORAGE_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#ifdef TINYLINK_FILE
	#include "One_File_File_LinkIt_One.h"
#endif

#include <LTask.h>
#include <LFlash.h>
#include <LSD.h>
#include <LStorage.h>

#define Drv LSD

class One_SD_Storage_LinkIt_One{
private:
#ifdef TINYLINK_FILE
	TL_File myFile;
#endif
public:
	One_SD_Storage_LinkIt_One();
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

extern One_SD_Storage_LinkIt_One TL_Storage;

#endif
