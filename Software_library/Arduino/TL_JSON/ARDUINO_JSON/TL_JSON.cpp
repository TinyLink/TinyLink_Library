#include "TL_JSON.h"

//TL_JSON::TL_JSON(const char* inbuff): res_json(inbuff){
//    StaticJsonBuffer<200> jsonBuffer;
//    //root = jsonBuffer.parseObject(res_json);
//    JsonObject* tmpJson = &root["ESP_IN_PC_OUT"].as<JsonObject>();
//}

void* parse2string(char* _inData, const char* objName, char* outPara){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    const char* outPara1 = root[objName];
    strcpy(outPara, outPara1);
}

void* parse2string(char* _inData, const char* objName, int count, char* outPara){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    const char* outPara1 = root[objName][count];
    strcpy(outPara, outPara1);
}

double parse2double(char* _inData, const char* objName){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    return root[objName];
}

double parse2double(char* _inData, const char* objName, int count){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    return root[objName][count];
}

int parse2int(char* _inData, const char* objName){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    return root[objName];
}

int parse2int(char* _inData, const char* objName, int count){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    return root[objName][count];
}

long parse2long(char* _inData, const char* objName){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    return root[objName];
}
long parse2long(char* _inData, const char* objName, int count){
    char inData[256];
    strcpy(inData, _inData);
    //inData = _inData;
    StaticJsonBuffer<200> jsonBuffer;
    JsonObject& root = jsonBuffer.parseObject(inData);
    return root[objName][count];
}
