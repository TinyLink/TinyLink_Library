#ifndef ARDUINO_HTTP_HTTP_ARDUINO_UNO_H
#define ARDUINO_HTTP_HTTP_ARDUINO_UNO_H

#include <Arduino.h>
#include "TL_Config.h"
#if TINYLINK_WIFI == ESP8266
	#include <WiFiEspClient.h>
#endif

class TL_HTTP{
private:
	bool parseURL(const char* url, char* host, char* para);
	Client* tcpClient;
public:
	TL_HTTP();
	TL_HTTP(const TL_HTTP& http);
	~TL_HTTP();
	TL_HTTP& operator=(const TL_HTTP& http);
	bool get(const String& url);
  	bool get(const char *url);
  	bool post(const String& url, const String& data);
  	bool post(const char* url, const char* data);
};

#endif
