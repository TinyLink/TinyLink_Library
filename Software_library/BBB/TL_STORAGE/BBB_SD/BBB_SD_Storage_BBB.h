#ifndef BBB_SD_STORAGE_BBB_H
#define BBB_SD_STORAGE_BBB_H

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cstring>
#include <cstddef>
#include <sys/types.h>  
#include <sys/stat.h>
#include "WString.h"

#include "TL_Config.h"
#ifdef TINYLINK_FILE
	#include "BBB_File_File_BBB.h"
#endif

using std::string;

class BBB_SD_Storage_BBB {
private:
	string tl_rootdir;
	const mode_t _dir_mode = 0755;
public:
	BBB_SD_Storage_BBB(const string& rootdir);
	//~BBB_SD_Storage_BBB();
	bool begin();
#ifdef TINYLINK_FILE
	TL_File open(const string &filepath, const string &openmode = "r");
	TL_File open(const String &filepath, const String &openmode = "r");
	TL_File open(const char *filepath, const char* openmode = "r");
#endif
	bool exists(const string &filepath);
	bool exists(const String &filepath);
	bool exists(const char *filepath);
	bool mkdir(const string &filepath);
	bool mkdir(const String &filepath);
	bool mkdir(const char *filepath);
	bool remove(const string &filepath); // remove a file
	bool remove(const String &filepath); // remove a file
	bool remove(const char *filepath);
	bool rmdir(const string &filepath); // remove a directory
	bool rmdir(const String &filepath); // remove a directory
	bool rmdir(const char *filepath); // remove a directory
};

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_STORAGE == BBB_SD
		extern BBB_SD_Storage_BBB TL_Storage;
	#endif
#endif

#endif
