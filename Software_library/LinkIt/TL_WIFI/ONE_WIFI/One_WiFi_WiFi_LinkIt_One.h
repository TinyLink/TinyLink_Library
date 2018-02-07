#ifndef ONE_WIFI_WIFI_LINKIT_ONE_H
#define ONE_WIFI_WIFI_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_HTTP.h"
#include "TL_MQTT.h"
#include <LWiFi.h>
#include <LWiFiClient.h>
#include "TL_Config.h"

#define WIFI_AUTH LWIFI_WPA

class One_WiFi_WiFi_LinkIt_One{
public:
	One_WiFi_WiFi_LinkIt_One(){}
	bool init();
	bool join(const String& SSID, const String& PASSWD);
	bool join(const char* SSID, const char* PASSWD);
	bool disjoin();
	TL_MQTT fetchMQTT();
	TL_HTTP fetchHTTP();
};

extern One_WiFi_WiFi_LinkIt_One TL_WiFi;

#endif
