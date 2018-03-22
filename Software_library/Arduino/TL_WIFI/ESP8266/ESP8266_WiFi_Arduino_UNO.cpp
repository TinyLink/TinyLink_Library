#include "ESP8266_WiFi_Arduino_UNO.h"

#if WIFI_UART_TX == 0 && WIFI_UART_RX == 1
	#define ESP_WiFi Serial
#else
	SoftwareSerial ESP_WiFi(WIFI_UART_TX, WIFI_UART_RX);
#endif

//SoftwareSerial ESP_WiFi(2, 3);

ESP8266_WiFi_Arduino_UNO::ESP8266_WiFi_Arduino_UNO():status(WL_IDLE_STATUS){
}

bool ESP8266_WiFi_Arduino_UNO::init(){
	ESP_WiFi.begin(9600);
	WiFi.init(&ESP_WiFi);
	return true;
}

bool ESP8266_WiFi_Arduino_UNO::join(String& SSID, String& PASSWD){
	char* _SSID = (char*)malloc(sizeof(char)*(SSID.length()+1));
	SSID.toCharArray(_SSID, SSID.length()+1);
	char* _PASSWD = (char*)malloc(sizeof(char)*(PASSWD.length()+1));
	PASSWD.toCharArray(_PASSWD, PASSWD.length()+1);
	bool res = join(_SSID, _PASSWD);
	free(_SSID);
	free(_PASSWD);
	return res;
}

bool ESP8266_WiFi_Arduino_UNO::join(char* SSID, char* PASSWD){
	unsigned long start = millis();
	char* _SSID = new char[strlen(SSID)+1];
	char* _PASSWD = new char[strlen(PASSWD)+1];
	while (status != WL_CONNECTED && millis() - start < 8000){
		status = WiFi.begin(SSID, PASSWD);
		delay(500);
	}
	if (status == WL_CONNECTED){
		return true;
	}else{
		return false;
	}
}

bool ESP8266_WiFi_Arduino_UNO::disjoin(){
	if(WiFi.disconnect() == WL_DISCONNECTED){
		return true;	
	}else{
		return false;
	}
}

#ifdef TINYLINK_HTTP
TL_HTTP ESP8266_WiFi_Arduino_UNO::fetchHTTP(){
	TL_HTTP oneHTTP;
	return oneHTTP;
}
#endif

#ifdef TINYLINK_MQTT
TL_MQTT ESP8266_WiFi_Arduino_UNO::fetchMQTT(){
	TL_MQTT oneMQTT;
	return oneMQTT;
}
#endif

ESP8266_WiFi_Arduino_UNO TL_WiFi;
