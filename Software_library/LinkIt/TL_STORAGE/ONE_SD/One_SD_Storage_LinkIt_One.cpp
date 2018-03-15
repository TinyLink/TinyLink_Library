#include "One_SD_Storage_LinkIt_One.h"

One_SD_Storage_LinkIt_One::One_SD_Storage_LinkIt_One(){
#ifdef TINYLINK_FILE
	TL_File myFile;
#endif
}

char* One_SD_Storage_LinkIt_One::StoC(String s){
	char* res = (char*)malloc(sizeof(char)*sizeof(s));
	s.toCharArray(res,sizeof(s));
	return res;
}

bool One_SD_Storage_LinkIt_One::begin(){
	pinMode(10, OUTPUT);
	return Drv.begin();
}

bool One_SD_Storage_LinkIt_One::exists(String path){
	char* temp = StoC(path);
	if(Drv.exists(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool One_SD_Storage_LinkIt_One::mkdir(String path){
	char* temp = StoC(path);
	if(Drv.mkdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool One_SD_Storage_LinkIt_One::rmdir(String path){
	char* temp = StoC(path);
	if(Drv.rmdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool One_SD_Storage_LinkIt_One::remove(String path){
	char* temp = StoC(path);
	if(Drv.remove(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

#ifdef TINYLINK_FILE
TL_File One_SD_Storage_LinkIt_One::open(String path, String mode){
	char pathStr[128];
	path.toCharArray(pathStr, 127);
	if(mode == "w"){
		Drv.remove(pathStr);
	}
	myFile = Drv.open(pathStr, (mode == "w" ? 0x13 : 0x01));
	return myFile;
}
#endif

One_SD_Storage_LinkIt_One TL_Storage;
