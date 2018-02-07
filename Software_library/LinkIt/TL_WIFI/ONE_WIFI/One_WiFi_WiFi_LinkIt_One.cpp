#include "One_WiFi_WiFi_LinkIt_One.h"

bool One_WiFi_WiFi_LinkIt_One::init(){
	LWiFi.begin();
	return true;
}

bool One_WiFi_WiFi_LinkIt_One::join(const String& SSID, const String& PASSWD){
	char* buffSSID = (char*)malloc(sizeof(char)*(SSID.length()+1));
  	SSID.toCharArray(buffSSID, SSID.length()+1);
	char* buffPASSWD = (char*)malloc(sizeof(char)*(PASSWD.length()+1));
  	PASSWD.toCharArray(buffPASSWD, PASSWD.length()+1);
	join(buffSSID,buffPASSWD);
	free(buffPASSWD);
	free(buffSSID);
}

bool One_WiFi_WiFi_LinkIt_One::join(const char* SSID, const char* PASSWD){
	unsigned long start = millis();
	int sig = 0;
	sig = LWiFi.connect(SSID, LWiFiLoginInfo(WIFI_AUTH, PASSWD));
	while ((0 == sig) && millis() - start < 10000){
		sig = LWiFi.connect(SSID, LWiFiLoginInfo(WIFI_AUTH, PASSWD));
		delay(200);
	}
	if(sig>0){
		return true;	
	}
	return false;
}

bool One_WiFi_WiFi_LinkIt_One::disjoin(){
	LWiFi.disconnect();
	return true;
}

TL_HTTP One_WiFi_WiFi_LinkIt_One::fetchHTTP(){
	TL_HTTP oneHTTP;
	return oneHTTP;
}

TL_MQTT One_WiFi_WiFi_LinkIt_One::fetchMQTT(){
	TL_MQTT oneMQTT;
	return oneMQTT;
}

One_WiFi_WiFi_LinkIt_One TL_WiFi;
