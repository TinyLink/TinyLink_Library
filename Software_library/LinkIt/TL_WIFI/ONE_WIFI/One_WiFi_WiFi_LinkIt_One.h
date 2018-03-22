#ifndef ONE_WIFI_WIFI_LINKIT_ONE_H
#define ONE_WIFI_WIFI_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#ifdef TINYLINK_HTTP
	#include "One_HTTP_HTTP_LinkIt_One.h"
#endif
#ifdef TINYLINK_MQTT
	#include "One_MQTT_MQTT_LinkIt_One.h"
#endif
#include <LWiFi.h>
#include <LWiFiClient.h>

#define WIFI_AUTH LWIFI_WPA

class One_WiFi_WiFi_LinkIt_One{
public:
	One_WiFi_WiFi_LinkIt_One(){}
	bool init();
	bool join(const String& SSID="", const String& PASSWD="");
	bool join(const char* SSID="", const char* PASSWD="");
	bool disjoin();
#ifdef TINYLINK_MQTT
	TL_MQTT fetchMQTT();
#endif
#ifdef TINYLINK_HTTP
	TL_HTTP fetchHTTP();
#endif
};

extern One_WiFi_WiFi_LinkIt_One TL_WiFi;

#endif
