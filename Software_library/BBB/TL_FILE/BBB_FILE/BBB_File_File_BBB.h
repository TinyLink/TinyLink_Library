#ifndef BBB_FILE_FILE_BBB_H
#define BBB_FILE_FILE_BBB_H

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

#endif
