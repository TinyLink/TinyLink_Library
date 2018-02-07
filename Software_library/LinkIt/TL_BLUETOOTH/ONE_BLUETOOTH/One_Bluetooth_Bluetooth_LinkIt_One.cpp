#include "One_Bluetooth_Bluetooth_LinkIt_One.h"

int One_Bluetoohth_Bluetooth::init(const String& name){
	int res = LBTServer.begin((uint8_t*)(name.c_str()));
	if(res == false){
		return -1;
	}
	return 0;
}

int One_Bluetoohth_Bluetooth::init(const char* name){
	int res = LBTServer.begin((uint8_t*)name);
	if(res == false){
		return -1;
	}
	return 0;
}

int One_Bluetoohth_Bluetooth::send(const String& data){
	if(!(LBTServer.connected())){
		LBTServer.accept(5);
	}
	if(LBTServer.connected()){
		int res = LBTServer.write(data.c_str());
		if(res > 0){
			return 0;
		}
	}
	return -1;
}

int One_Bluetoohth_Bluetooth::send(const char* data){
	if(!(LBTServer.connected())){
		LBTServer.accept(5);
	}
	if(LBTServer.connected()){
		int res = LBTServer.write(data);
		if(res > 0){
			return 0;
		}
	}
	return -1;
}

int One_Bluetoohth_Bluetooth::recv(String& data){
	if(!LBTServer.connected()){
		LBTServer.accept(5);
	}
	data = LBTServer.readString();
	if(data == ""){
		return -1;	
	}
	return 0;
}

int One_Bluetoohth_Bluetooth::recv(char* data){
	if(!LBTServer.connected()){
		LBTServer.accept(5);
	}
	strcpy(data, LBTServer.readString().c_str());
	if(strlen(data) == 0){
		return -1;
	}
	return 0;
}

One_Bluetoohth_Bluetooth TL_Bluetooth;
