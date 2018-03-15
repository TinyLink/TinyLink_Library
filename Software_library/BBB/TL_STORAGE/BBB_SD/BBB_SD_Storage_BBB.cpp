#include "BBB_SD_Storage_BBB.h"

BBB_SD_Storage_BBB::BBB_SD_Storage_BBB(const string& rootdir){
	tl_rootdir = rootdir + "/";
	if (access(tl_rootdir.c_str(), F_OK) != 0){
		if(::mkdir(tl_rootdir.c_str(), _dir_mode) !=0)
		{
			perror("Creating directory Error");
			exit(-1);
		}
	}
	else {
		struct stat buffer = {0};
		stat(tl_rootdir.c_str(), &buffer);
		if (! S_ISDIR(buffer.st_mode)) {
			perror("Already exists a file with the same name");
			exit(-2);
		}
		else if ( (buffer.st_mode & _dir_mode) != _dir_mode) {
			if( chmod(tl_rootdir.c_str(), _dir_mode) != 0) {
				perror("Changing authority of the same directory Error");
				exit(-3);
			}
		}
	}
}

bool BBB_SD_Storage_BBB::begin(){return 1;}// initialize sd mock  mkdir /var/lib/cloud9/SD_MOCK

#ifdef TINYLINK_FILE
TL_File BBB_SD_Storage_BBB::open(const string &filepath, const string &mode){
	return open(filepath.c_str(), mode.c_str());
}

TL_File BBB_SD_Storage_BBB::open(const String &filepath, const String &mode){
	return open(filepath.c_str(), mode.c_str());
}

TL_File BBB_SD_Storage_BBB::open(const char *filepath, const char *mode){
	char *temp = (char*)malloc(sizeof(char) * (tl_rootdir.size() + strlen(filepath) + 1));
	strcpy(temp, tl_rootdir.c_str());
	strcat(temp, filepath);
	TL_File temp_file(temp, mode);
	free(temp);
	return temp_file;
}
#endif

bool BBB_SD_Storage_BBB::exists(const string& path){
	return exists(path.c_str());
}

bool BBB_SD_Storage_BBB::exists(const String& path){
	return exists(path.c_str());
}

bool BBB_SD_Storage_BBB::exists(const char *path){
	if(strlen(path) == 0)
		return 0;
	if (access((tl_rootdir + path).c_str(), F_OK) == 0)
		return 1;
	return 0; 
}


bool BBB_SD_Storage_BBB::mkdir(const char  *path){
	if (path == NULL) return 0;
	char *temp = strdup((tl_rootdir + path).c_str());
	char *pos = temp + tl_rootdir.length();
	for(; *pos != '\0'; ++ pos) {
		if(*pos == '/') {
			*pos = '\0';
			if(access(temp, F_OK) != 0)
				if(::mkdir(temp, _dir_mode) != 0 )
					return 0;
			*pos = '/';
		}
	}
	free(temp);
	if(*(pos - 1) != '/')
		return ::mkdir((tl_rootdir + path).c_str(), _dir_mode) == 0 ? 1:0;
	return 1;
}
bool BBB_SD_Storage_BBB::mkdir(const string &path){ return mkdir(path.c_str());}
bool BBB_SD_Storage_BBB::mkdir(const String &path){ return mkdir(path.c_str());}


bool BBB_SD_Storage_BBB::remove(const char *path){ return ::remove((tl_rootdir + path).c_str()) == 0 ? 1:0; }
bool BBB_SD_Storage_BBB::remove(const string &path){ return remove(path.c_str()); }
bool BBB_SD_Storage_BBB::remove(const String &path){ return remove(path.c_str()); }

bool BBB_SD_Storage_BBB::rmdir(const char *path){ return ::remove((tl_rootdir + path).c_str()) == 0 ? 1:0; } 
bool BBB_SD_Storage_BBB::rmdir(const string &path){ return remove(path.c_str()); } 
bool BBB_SD_Storage_BBB::rmdir(const String &path){ return remove(path.c_str()); } 

#if PLATFORM == 3 && BOARD == 1005
	#if TINYLINK_STORAGE == BBB_SD
		BBB_SD_Storage_BBB TL_Storage("/var/lib/cloud9/SD_MOCK");
	#endif
#endif
