#include "RPI_File_File_RPI.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <cstdio>
#include <cstring>

namespace tinylink{
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
