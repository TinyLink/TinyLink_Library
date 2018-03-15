#ifndef ESP8266_WIFI_ARDUINO_UNO_H
#define ESP8266_WIFI_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#ifdef TINYLINK_MQTT
	#include "Arduino_MQTT_MQTT_Arduino_UNO.h"
#endif

#ifdef TINYLINK_HTTP
	#include "Arduino_HTTP_HTTP_Arduino_UNO.h"
#endif
#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include <SoftwareSerial.h>


class ESP8266_WiFi_Arduino_UNO{
private:
	int status;
public:
	ESP8266_WiFi_Arduino_UNO();
	bool init();
	bool join(String& SSID, String& PASSWD);
	bool join(char* SSID, char* PASSWD);
	bool disjoin();
#ifdef TINYLINK_MQTT
	TL_MQTT fetchMQTT();
#endif
#ifdef TINYLINK_HTTP
	TL_HTTP fetchHTTP();
#endif
};

extern ESP8266_WiFi_Arduino_UNO TL_WiFi;

#endif
