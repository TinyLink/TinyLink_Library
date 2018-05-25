#ifndef WIFI_USB_WIFI_RPI_H
#define WIFI_USB_WIFI_RPI_H
#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <unistd.h>

#include "TL_Config.h"
#include "WString.h"
#ifdef TINYLINK_HTTP
	#include "RPI_HTTP_HTTP_RPI.h"
#endif
#ifdef TINYLINK_MQTT
	#include "RPI_MQTT_MQTT_RPI.h"
#endif

#ifdef TINYLINK_TCP
	#include "RPI_TCP_TCP_RPI.h"
#endif

using namespace std;

namespace tinylink {

	class Wifi_Network {
	public:
		Wifi_Network();
		~Wifi_Network();
		bool init();// initialize	

		bool join(const char* SSID, const char* P);
		bool join(const string& SSID, const string& PassW = "");// choose the AP and set the password, then join the network
		bool join(const String& SSID, const String& PassW = "");
		bool disjoin();
		bool available();// test whether the network is OK
		
#ifdef TINYLINK_HTTP
		TL_HTTP& fetchHTTP();
#endif
#ifdef TINYLINK_MQTT
		TL_MQTT& fetchMQTT();
#endif
#ifdef TINYLINK_TCP
		TL_TCP& fetchTCP();
#endif
	};
}

extern tinylink::Wifi_Network TL_WiFi;
#endif
