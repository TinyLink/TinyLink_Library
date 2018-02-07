#include "SD_Shield_Storage_Arduino_UNO.h"

SD_Card::SD_Card(){
	TL_File myFile;
}

char* SD_Card::StoC(String s){
	char* res = (char*)malloc(sizeof(char)*sizeof(s));
	s.toCharArray(res,sizeof(s));
	return res;
}

bool SD_Card::begin(){
	if (!SD.begin(4)) {
		return false;
	}
	return true;
}

bool SD_Card::exists(String path){
	char* temp = StoC(path);
	if(SD.exists(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool SD_Card::mkdir(String path){
	char* temp = StoC(path);
	if(SD.mkdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool SD_Card::rmdir(String path){
	char* temp = StoC(path);
	if(SD.rmdir(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

bool SD_Card::remove(String path){
	char* temp = StoC(path);
	if(SD.remove(temp)){
		free(temp);
		return true;
	}else{
		free(temp);
		return false;
	}
}

TL_File SD_Card::open(String path, String mode){
	char* temp = StoC(path);
	if(mode == "w"){
		remove(temp);
	}
	myFile = SD.open(temp, (mode == "w" ? FILE_WRITE : FILE_READ));
	free(temp);
	return myFile;
}

SD_Card TL_Storage;
