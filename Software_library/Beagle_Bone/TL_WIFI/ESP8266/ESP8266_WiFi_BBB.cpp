#include "ESP8266_WiFi_BBB.h"

ESP8266_WiFi::ESP8266_WiFi(){
  state = 0;
}

void ESP8266_WiFi::send(String str){
  char* buff = (char*)malloc(sizeof(char)*(str.length()+1));
  str.toCharArray(buff, str.length()+1);
  send(buff);
  free(buff);
}

void ESP8266_WiFi::send(char* str){
  int len = strlen(str);
  //DEBUG.println("send:");
  //DEBUG.println(str);
  if (len < 4 || str[len - 2] != '\r' || str[len - 1] != '\n'){
    //DEBUG.println("AT command error");
    return;
  }
  ESP8266_WIFI_Serial.write(str);
}

String ESP8266_WiFi::recv(int type,unsigned long timeout){
  String str;
  int recvFlag = 0;
  unsigned long start = millis();
  while (!recvFlag && millis() - start < timeout)
  {
    while(ESP8266_WIFI_Serial.available()){
      str += (char)ESP8266_WIFI_Serial.read();
    }
    switch(type){
      case 1:{
        if(str.indexOf("OK") != -1){
          ESP8266_WIFI_Serial.flush();
          recvFlag = 1;
        }
        break;
      }
      case 2:{
        if(str.indexOf("OK") != -1 || str.indexOf("busy") != -1 || str.indexOf("FAIL") != -1){
          ESP8266_WIFI_Serial.flush();
          recvFlag = 1;
        }
        break;
      }
      case 3:{
        if(str.indexOf("CLOSED") != -1){
          ESP8266_WIFI_Serial.flush();
          recvFlag = 1;
        }
        break;
      }
      case 4:{
        if(str.indexOf("OK") != -1 || str.indexOf("ERROR") != -1){
          ESP8266_WIFI_Serial.flush();
          recvFlag = 1;
        }
        break;
      }
      case 5:{
        if(str.indexOf("OK") != -1 || str.indexOf("ERROR") != -1){
          ESP8266_WIFI_Serial.flush();
          recvFlag = 1;
        }
        break;
      }
      case 6:{
        if(str.indexOf("OK") != -1 || str.indexOf("FAIL") != -1){
          ESP8266_WIFI_Serial.flush();
          recvFlag = 1;
        }
        break;
      }
    }
  }
  //DEBUG.println("recv:");
  //DEBUG.println(str);
  return str;
}

bool ESP8266_WiFi::init(){
  ESP8266_WIFI_Serial.begin(20000);
  //DEBUG.begin(20000);
  send("AT\r\n");
  String rtn = recv(1,3000);
  if (rtn.indexOf("OK") != -1){
    return true;
  }else{
    return false;
  }
}

bool ESP8266_WiFi::join(const String& SSID, const String& PASSWD)
{
	return join(SSID.c_str(), PASSWD.c_str());
}

bool ESP8266_WiFi::join(const char* SSID, const char* PASSWD)
{
  send(String("AT+CWJAP=\"") + SSID + "\",\"" + PASSWD + "\"\r\n");
  String rtn = recv(2,10000);
  if (rtn.indexOf("OK") != -1){
    return true;
  }else{
    return false;
  }
}

bool ESP8266_WiFi::disjoin()
{
  send("AT+CWQAP\r\n");
  String rtn = recv(2,2000);
  if (rtn.indexOf("OK") != -1){
    return true;
  }else{
    return false;
  }
}

bool ESP8266_WiFi::setConfig()
{
  return true;
}

bool ESP8266_WiFi::parseURL(const char* url, char* host, char* para){
  const char *uPtr = url;
  char  *_host, *_para;
  _host = host;
  _para = para;
  int state = 0;
  while (*uPtr != '\0'){
    if (state == 0 || state == 1){
      *_host = *uPtr;
      _host++;
    }
    if (*uPtr == '/'){
      if (state == 1 && *(uPtr - 1) != '/'){
        *(_host - 1) = '\0';
        state = 2;
      }
      if (state == 0) // first /
      {
        if (*(uPtr + 1) == '/') // first //, indicating http://
        {
          if (_host != host){
            _host = host;
          }
          state = 1;
          uPtr++;
        }else  // indicating no http://, just the hostname
        {
          *(_host - 1)= '\0';
          state = 2;
        }
      }
    }
    if (state == 2){
      *_para = *uPtr;
      _para++;
    }
    uPtr++;
  }
  *_para = '\0';
  if (state == 2){
    return true;
  }else{
    return false;
  }
}

bool ESP8266_WiFi::get(const String& url){
  return get(url.c_str());
}

bool ESP8266_WiFi::get(const char* url){
  char host[32], para[200];
  responce = String();
  if (parseURL(url, host, para) == false){
    return false;
  }
  String paraStr = String("GET ") + para + " HTTP/1.1\r\nHost:" + host + "\r\n";
  send(String("AT+CIPSTART=\"TCP\",\"") + host + "\",80\r\n");    
  String rtn = recv(4,2000);
  if (rtn.indexOf("OK") == -1 && rtn.indexOf("CONNECTED")==-1){
     return false;
  }
  send(String("AT+CIPSEND=") + String(paraStr.length()+2) + String("\r\n"));  
  rtn = recv(5,200);
  if (rtn.indexOf("ERROR") != -1){
    return false;
  }
  send(String(paraStr) + "\r\n");
  rtn = recv(6,1500);
  //DEBUG.println(rtn);
  if (rtn.indexOf("OK") == -1){
    return false;
  }
  responce = rtn;
  //send("AT+CIPCLOSE\r\n");
  //recv(1,3000);
  return true;
}

bool ESP8266_WiFi::post(const String& url, const String& data){
	return post(url.c_str(), data.c_str());
}

bool ESP8266_WiFi::post(const char* url, const char* data){
  char host[32], para[200];
  responce = String();
  if (parseURL(url, host, para) == false){
    return false;
  } 
  String paraStr = String("POST ") + para + " HTTP/1.1\r\nHost: " + host + "\r\nContent-Type: application/x-www-form-urlencoded\r\n"+"Content-Length: " + String(strlen(data)) +"\r\n\r\n"+data;
  send(String("AT+CIPSTART=\"TCP\",\"") + host + "\",80\r\n");    
  String rtn = recv(4,2000);
  if (rtn.indexOf("OK") == -1 && rtn.indexOf("CONNECTED")==-1){
     return false;
  }
  send(String("AT+CIPSEND=") + String(paraStr.length()+2) + String("\r\n"));  
  rtn = recv(5,200);
  if (rtn.indexOf("ERROR") != -1){
    return false;
  }
  send(String(paraStr) + "\r\n");
  rtn = recv(6,1500);
  //DEBUG.println(rtn);
  if (rtn.indexOf("OK") == -1){
    return false;
  }
  responce = rtn;
  //send("AT+CIPCLOSE\r\n");
  //recv(1,3000);
  return true;
}

String ESP8266_WiFi::getResponce(){
  return responce.substring(responce.indexOf("<html>"));
}

String ESP8266_WiFi::getRawResponce(){
  return responce.substring(responce.indexOf(":") + 1);
}

#if PLATFORM == 3 && BOARD == 1005
#if WIFI == ESP8266
ESP8266_WiFi TL_WiFi;
#endif
#endif
