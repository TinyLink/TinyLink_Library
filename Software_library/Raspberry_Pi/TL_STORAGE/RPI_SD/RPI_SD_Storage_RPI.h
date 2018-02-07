#ifndef TINYLINK_STORAGE
#define TINYLINK_STORAGE

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

class RPI_SD_Storage {
private:
    string tl_rootdir;
    const mode_t _dir_mode = 0755;
public:
    RPI_SD_Storage(const string& rootdir);
    //~BBB_SD_Storage();
    bool begin();
    File open(const string &filepath, const string &openmode = "r");
    File open(const String &filepath, const String &openmode = "r");
    File open(const char *filepath, const char* openmode = "r");
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

}

extern tinylink::RPI_SD_Storage TL_Storage;
typedef tinylink::File TL_File;

#endif
