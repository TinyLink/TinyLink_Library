#ifndef ESP8266_WIFI_ARDUINO_UNO_H
#define ESP8266_WIFI_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_HTTP.h"
#include "TL_MQTT.h"
#include <WiFiEsp.h>
#include <WiFiEspClient.h>
#include "TL_Config.h"
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
	TL_MQTT fetchMQTT();
	TL_HTTP fetchHTTP();
};

extern ESP8266_WiFi_Arduino_UNO TL_WiFi;

#endif
