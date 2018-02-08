#ifndef ESP8266_WIFI_BBB_H
#define ESP8266_WIFI_BBB_H

#ifndef ESP8266_WIFI_Serial
#define ESP8266_WIFI_Serial TL_Serial
#endif

#include "UART.h"
#include "CLOCK.h"

class ESP8266_WiFi
{

private:
  int state; //0 disjoint, 1 joint, 2 got ip, 3 tcp/udp connected, 4 disconnected
  String responce;
  
  void send(String str);
  void send(char* str);
  String recv(int type,unsigned long timeout=2000);
  bool parseURL(const char* url, char* host, char* para);

public:
  ESP8266_WiFi();
  bool init();
  bool join(const String& SSID, const String& PASSWD = "");
  bool join(const char* SSID, const char* PASSWD = "");
  bool disjoin();
  bool setConfig();
  bool get(const String& url);
  bool get(const char *url);
  bool post(const String& url, const String& data);
  bool post(const char* url, const char* data);
  String getResponce();
  String getRawResponce();
};


#if PLATFORM == 3 && BOARD == 1005
#if WIFI == ESP8266
extern ESP8266_WiFi TL_WiFi;
#endif
#endif
#endif
