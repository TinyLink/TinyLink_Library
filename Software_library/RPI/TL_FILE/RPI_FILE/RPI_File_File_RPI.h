#ifndef RPI_FILE_FILE_RPI_H
#define RPI_FILE_FILE_RPI_H

#include <sys/types.h>
#include <unistd.h>
#include <string>
#include "WString.h"
using std::string;

namespace tinylink {

class File {
private:
    FILE* fp;
    char* filepath;
public:
    File():fp(NULL), filepath(NULL) {}
    File(const char *filepath, const char *mode);
    File(const File& temp);
    File& operator=(const File& temp);
    ~File();
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

}

typedef tinylink::File TL_File;

#endif
