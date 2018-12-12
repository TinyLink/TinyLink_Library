#ifndef ARDUINO_JSON_JSON_ARDUINO_H
#define ARDUINO_JSON_JSON_ARDUINO_H

#include "ArduinoJson.h"


// void* parse2string(char* _inData, const char* objName, char* outPara);    
// void* parse2string(char* _inData, const char* objName, int count, char* outPara);
// double parse2double(char* _inData, const char* objName);
// double parse2double(char* _inData, const char* objName, int count);
// int parse2int(char* _inData, const char* objName);
// int parse2int(char* _inData, const char* objName, int count);
// long parse2long(char* _inData, const char* objName);
// long parse2long(char* _inData, const char* objName, int count);

class TL_JSON{
private:
    //JsonVariant& root;
    int json;
//public:
    //TL_JSON(const char* inbuff);
    //~TL_JSON(){};
    //int initParse(char* inbuff){};
};
void* parse2string(char* _inData, const char* objName, char* outPara);
void* parse2string(char* _inData, const char* objName, int count, char* outPara);
double parse2double(char* _inData, const char* objName);
double parse2double(char* _inData, const char* objName, int count);
int parse2int(char* _inData, const char* objName);
int parse2int(char* _inData, const char* objName, int count);
long parse2long(char* _inData, const char* objName);
long parse2long(char* _inData, const char* objName, int count);


#endif