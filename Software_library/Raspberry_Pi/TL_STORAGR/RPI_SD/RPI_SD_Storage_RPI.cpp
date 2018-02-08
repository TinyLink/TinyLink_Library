#include "RPI_SD_Storage_RPI.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

namespace tinylink{
RPI_SD_Storage::RPI_SD_Storage(const string& rootdir){
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




bool RPI_SD_Storage::begin(){return 1;}// initialize sd mock  mkdir /var/lib/cloud9/SD_MOCK

File RPI_SD_Storage::open(const string &filepath, const string &mode){
    return open(filepath.c_str(), mode.c_str());
}

File RPI_SD_Storage::open(const String &filepath, const String &mode){
    return open(filepath.c_str(), mode.c_str());
}

File RPI_SD_Storage::open(const char *filepath, const char *mode){
    char *temp = (char*)malloc(sizeof(char) * (tl_rootdir.size() + strlen(filepath) + 1));
    strcpy(temp, tl_rootdir.c_str());
    strcat(temp, filepath);
    File temp_file(temp, mode);
    free(temp);
    return temp_file;
}

bool RPI_SD_Storage::exists(const string& path){
    return exists(path.c_str());
}

bool RPI_SD_Storage::exists(const String& path){
    return exists(path.c_str());
}

bool RPI_SD_Storage::exists(const char *path){
    if(strlen(path) == 0)
        return 0;
    if (access((tl_rootdir + path).c_str(), F_OK) == 0)
        return 1;
    return 0; 
}


bool RPI_SD_Storage::mkdir(const char  *path){
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
bool RPI_SD_Storage::mkdir(const string &path){ return mkdir(path.c_str());}
bool RPI_SD_Storage::mkdir(const String &path){ return mkdir(path.c_str());}


bool RPI_SD_Storage::remove(const char *path){ return ::remove((tl_rootdir + path).c_str()) == 0 ? 1:0; }
bool RPI_SD_Storage::remove(const string &path){ return remove(path.c_str()); }
bool RPI_SD_Storage::remove(const String &path){ return remove(path.c_str()); }

bool RPI_SD_Storage::rmdir(const char *path){ return ::remove((tl_rootdir + path).c_str()) == 0 ? 1:0; } 
bool RPI_SD_Storage::rmdir(const string &path){ return remove(path.c_str()); } 
bool RPI_SD_Storage::rmdir(const String &path){ return remove(path.c_str()); } 

	
	
    File::File(const char *filename, const char *mode):fp(NULL), filepath(NULL) {
        filepath = (char*)malloc(sizeof(char) * (strlen(filename) + 1));
        strcpy(filepath, filename);
        fp = fopen(filepath, mode);
    }   

    File::File(const File &temp): fp(temp.fp), filepath(NULL) {
        filepath = (char*)malloc(sizeof(char) * (strlen(temp.filepath) + 1));
        strcpy(filepath, temp.filepath);
    }   

    File& File::operator=(const File &file1) {
        // 判断两个实例是否相同
        if(this != &file1) {
            //创建一个临时实例，在栈上, 防止内存分配不成功
            File temp(file1);
            fp = temp.fp;
            char* path = temp.filepath;
            temp.filepath = filepath;
            filepath = path;
        }
        return *this;   

        // 另一种实现方式
    /*  char *temppath = (char*)malloc(sizeof(char) * (strlen(temp.filepath) + 1));
        free(filepath);
        filepath = temppath;
        fp = temp.fp;
        return *this;*/ 

    }   

    File::~File() {
        free(filepath);
    }   

    void File::close(){
        fclose(fp);
        //free(filepath);
    }   

    int File::read(){
        uint8_t x;
        int len = fread(&x, 1, 1, fp);
        if (len < 1)
            return -1;
        else
            return ((int)x) & 0xFF;
    }   

    int File::read(char* buf, size_t size){
        return fread(buf, 1, size, fp);
    }
     
    int File::peek(){
        int c;
        c = getc(fp);
        if (EOF == c){
            return -1;
        }
        ungetc(c, fp);
        return c;
    }   
    

    size_t File::write(const uint8_t data){
        return fwrite(&data, sizeof(data), 1, fp);
    }   

    size_t File::write(const char data){
        return fwrite(&data, sizeof(data), 1, fp);
    }   

    size_t File::write(const char* data){
        return fwrite(data, sizeof(data[0]), strlen(data), fp);
    }   

    size_t File::write(const char* data, size_t size){
        return fwrite(data, sizeof(data[0]), size, fp);
    }
    size_t File::write(const string &data){
        const char* ch = data.c_str();
        return fwrite(ch, sizeof(ch[0]), strlen(ch), fp);
    }
    size_t File::write(const String &data){
        const char* ch = data.c_str();
        return fwrite(ch, sizeof(ch[0]), strlen(ch), fp);
    }   

    size_t File::write(const string &data, size_t size){
        const char* ch = data.c_str();
        return fwrite(ch, sizeof(ch[0]), size, fp);
    }
    size_t File::write(const String &data, size_t size){
        const char* ch = data.c_str();
        return fwrite(ch, sizeof(ch[0]), size, fp);
    }   

    unsigned long File::position(){
        return ftell(fp);
    }   

    int File::seek(long offset, int origin){
        return fseek(fp, offset, origin);
    }   

    void File::rewind(){
        ::rewind(fp);
    }   

    unsigned long File::size(){
        struct stat temp;
        stat(filepath, &temp);
        return temp.st_size;
    }
}

tinylink::RPI_SD_Storage TL_Storage("./tmp");
