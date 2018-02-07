#include "One_SD_Storage_LinkIt_One.h"

Internal_SD::Internal_SD(){
	TL_File myFile;
}

char* Internal_SD::StoC(String s){
	char* res = (char*)malloc(sizeof(char)*sizeof(s));
	s.toCharArray(res,sizeof(s));
	return res;
}

bool Internal_SD::begin(){
	pinMode(10, OUTPUT);
	return Drv.begin();
}

bool Internal_SD::exists(String path){
	char* temp = StoC(path);
	if(Drv.exists(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool Internal_SD::mkdir(String path){
	char* temp = StoC(path);
	if(Drv.mkdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool Internal_SD::rmdir(String path){
	char* temp = StoC(path);
	if(Drv.rmdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool Internal_SD::remove(String path){
	char* temp = StoC(path);
	if(Drv.remove(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}


TL_File Internal_SD::open(String path, String mode){
	char pathStr[128];
	path.toCharArray(pathStr, 127);
	if(mode == "w"){
		Drv.remove(pathStr);
	}
	myFile = Drv.open(pathStr, (mode == "w" ? 0x13 : 0x01));
	return myFile;
}

Internal_SD TL_Storage;
