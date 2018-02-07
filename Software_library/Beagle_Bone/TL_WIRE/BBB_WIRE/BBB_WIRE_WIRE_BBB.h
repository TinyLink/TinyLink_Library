#ifndef BBB_WIRE_WIRE_BBB_H
#define BBB_WIRE_WIRE_BBB_H

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "TL_Config.h"
#include "TL_HTTPClient.h"
#include "TL_MQTTClient.h"

using namespace std;

class Wire_Network {
private:

public:
	Wire_Network();
	~Wire_Network();
	bool init();// initialize
	bool setConfig(const char* IP, const char* netmask, const char* gateway, const char * dns_nameservers);

	bool setConfig(const String& IP, const String& netmask, const String& gateway, const String& dns_nameservers);// set IP gateway dns-nameserver

	bool setConfig(const string& IP, const string& netmask, const string& gateway, const string& dns_nameservers);// set IP gateway dns-nameserver

	bool available();// test whether the network is OK
	TL_HTTP fetchHTTP();
	TL_MQTT fetchMQTT();
};

#if PLATFORM == 3 && BOARD == 1005
#if WIRE == BBB_WIRE
extern Wire_Network TL_Wire;
#endif
#endif

#endif
