#ifndef ONE_BLUETOOTH_BLUETOOTH_LINKIT_ONE_H
#define ONE_BLUETOOTH_BLUETOOTH_LINKIT_ONE_H

#include <Arduino.h>
#include <LBT.h>
#include <LBTServer.h>
#include "TL_Config.h"

class One_Bluetoohth_Bluetooth{
public:
	One_Bluetoohth_Bluetooth(){}
	int init(const String& name);
	int init(const char* name);
	int send(const char* data);
	int send(const String& data);
	int recv(char* data);
	int recv(String& data);
};

extern One_Bluetoohth_Bluetooth TL_Bluetooth;

#endif
