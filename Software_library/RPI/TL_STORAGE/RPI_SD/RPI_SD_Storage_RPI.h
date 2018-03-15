#ifndef RPI_SD_Storage_RPI_H
#define RPI_SD_Storage_RPI_H

#include <sys/types.h>
#include <unistd.h>
#include <string>
#include "WString.h"
#include "TL_Config.h"
#ifdef TINYLINK_FILE
	#include "RPI_File_File_RPI.h"
#endif

using std::string;

namespace tinylink {

class RPI_SD_Storage {
private:
    string tl_rootdir;
    const mode_t _dir_mode = 0755;
public:
    RPI_SD_Storage(const string& rootdir);
    //~BBB_SD_Storage();
    bool begin();
#ifdef TINYLINK_FILE
    File open(const string &filepath, const string &openmode = "r");
    File open(const String &filepath, const String &openmode = "r");
    File open(const char *filepath, const char* openmode = "r");
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

}

extern tinylink::RPI_SD_Storage TL_Storage;

#endif
