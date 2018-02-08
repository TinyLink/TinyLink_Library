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

using std::string;


class TL_File {
private:
	FILE* fp;
	char* filepath;
public:
	TL_File():fp(NULL), filepath(NULL) {}
	TL_File(const char *filepath, const char *mode);
	TL_File(const TL_File& temp);
	TL_File& operator=(const TL_File& temp);
	~TL_File();
	void close();
	int read();
	int read(char * buf, size_t size);
	int peek();
	size_t write(const uint8_t data);
	size_t write(const char data);
	size_t write(const char* data);
	size_t write(const char* data, size_t size);
	size_t write(const string &data);
	size_t write(const string &data, size_t size);
	size_t write(const String &data);
	size_t write(const String &data, size_t size);
	unsigned long position();
	int seek(long offset, int origin = SEEK_SET);
	void rewind(); // moves the position indicator to the begin of the given File object
	unsigned long size(); //
	operator void*() {return fp;}
	bool operator !() {
		return fp == NULL;
	}
};

class BBB_SD_Storage {
private:
	string tl_rootdir;
	const mode_t _dir_mode = 0755;
public:
	BBB_SD_Storage(const string& rootdir);
	//~BBB_SD_Storage();
	bool begin();
	TL_File open(const string &filepath, const string &openmode = "r");
	TL_File open(const String &filepath, const String &openmode = "r");
	TL_File open(const char *filepath, const char* openmode = "r");
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
#if STORAGE == BBB_SD
extern BBB_SD_Storage TL_Storage;
#endif
#endif

#endif