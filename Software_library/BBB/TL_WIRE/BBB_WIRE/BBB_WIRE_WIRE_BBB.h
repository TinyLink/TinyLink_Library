#ifndef BBB_WIRE_WIRE_BBB_H
#define BBB_WIRE_WIRE_BBB_H

#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

#include "TL_Config.h"
#ifdef TINYLINK_HTTP
#include "BBB_HTTP_HTTP_BBB.h"
#endif
#ifdef TINYLINK_MQTT
#include "BBB_MQTT_MQTT_BBB.h"
#endif

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
#ifdef TINYLINK_HTTP
	TL_HTTP fetchHTTP();
#endif
#ifdef TINYLINK_MQTT
	TL_MQTT fetchMQTT();
#endif
};

#if PLATFORM == 3 && BOARD == 1005
	extern Wire_Network TL_Wire;
#endif

#endif
