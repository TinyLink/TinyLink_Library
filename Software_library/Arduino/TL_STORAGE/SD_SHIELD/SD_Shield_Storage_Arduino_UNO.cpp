#include "SD_Shield_Storage_Arduino_UNO.h"

SD_Shield_Storage_Arduino_UNO::SD_Shield_Storage_Arduino_UNO(){
#ifdef TINYLINK_FILE
	TL_File myFile;
#endif
}

char* SD_Shield_Storage_Arduino_UNO::StoC(String s){
	char* res = (char*)malloc(sizeof(char)*sizeof(s));
	s.toCharArray(res,sizeof(s));
	return res;
}

bool SD_Shield_Storage_Arduino_UNO::begin(){
	if (!SD.begin(4)) {
		return false;
	}
	return true;
}

bool SD_Shield_Storage_Arduino_UNO::exists(String path){
	char* temp = StoC(path);
	if(SD.exists(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool SD_Shield_Storage_Arduino_UNO::mkdir(String path){
	char* temp = StoC(path);
	if(SD.mkdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool SD_Shield_Storage_Arduino_UNO::rmdir(String path){
	char* temp = StoC(path);
	if(SD.rmdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool SD_Shield_Storage_Arduino_UNO::remove(String path){
	char* temp = StoC(path);
	if(SD.remove(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

#ifdef TINYLINK_FILE
TL_File SD_Shield_Storage_Arduino_UNO::open(String path, String mode){
	char* temp = StoC(path);
	if(mode == "w"){
		remove(temp);
	}
	myFile = SD.open(temp, (mode == "w" ? FILE_WRITE : FILE_READ));
	free(temp);
	return myFile;
}
#endif

SD_Shield_Storage_Arduino_UNO TL_Storage;
