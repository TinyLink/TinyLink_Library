#ifndef ONE_HTTP_HTTP_LINKIT_ONE_H
#define ONE_HTTP_HTTP_LINKIT_ONE_H

#include <Arduino.h>
#include "TL_Config.h"
#if TINYLINK_WIFI == ONE_WIFI
	#include <LWiFiClient.h>
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
