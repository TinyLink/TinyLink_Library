# include "WiFi_USB_WiFi_RPI.h"

namespace tinylink {

	Wifi_Network::Wifi_Network(){
		//httpClient = new CLibcurl();
	}	

	Wifi_Network::~Wifi_Network(){
		//delete httpClient;
		//disjoin();
	}	

	bool Wifi_Network::init() { return 1;} // dummy funtion	

	bool Wifi_Network::join(const char* SSID, const char* PassW) {
		if (!SSID){
			perror("SSID is null string\n");
			exit(-1);
		}
		system("sudo nmcli device connect wlan1");
		string comm = string("sudo nmcli device wifi connect ")+string(SSID)+" password "+string(PassW)+" ifname wlan1";
		int res = system(comm.c_str());
		if(-1 == res){
			return 0;
		}else{
			return 1;
		}
	}	

	bool Wifi_Network::join(const string& SSID, const string& PassW) {
		return join(SSID.c_str(), PassW.c_str());
	}	

	bool Wifi_Network::join(const String& SSID, const String& PassW) {
		return join(SSID.c_str(), PassW.c_str());
	}	
	

	bool Wifi_Network::disjoin(){
		int result = system("sudo nmcli device disconnect wlan1");
		if ( 0 == result) {
			cout << "Success disjoin network"<<endl;
			return 1;
		}
		cout << "Calling join command error !" <<endl;
		return 0;	

	}// dummy funtion	

	bool Wifi_Network::available() {
		return 1;
	}	

#ifdef TINYLINK_HTTP
	TL_HTTP& Wifi_Network::fetchHTTP() {
		static TL_HTTP http_client;
		return http_client;
	}
#endif
#ifdef TINYLINK_MQTT
	TL_MQTT& Wifi_Network::fetchMQTT() {
		static TL_MQTT mqtt_client;
		return mqtt_client;
	}
#endif
#ifdef TINYLINK_TCP
	TL_TCP& Wifi_Network::fetchTCP(){
		static TL_TCP tcp_client;
		return tcp_client;
	}
#endif
}


tinylink::Wifi_Network TL_WiFi;

