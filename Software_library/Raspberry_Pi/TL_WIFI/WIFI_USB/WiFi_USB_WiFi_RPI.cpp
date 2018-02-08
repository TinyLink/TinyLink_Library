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
		// configuration
		if (!SSID){
			perror("SSID is null string\n");
			exit(-1);
		}
		system("sudo chmod 111 /home/pi/TinyLink_Config/wifi_config.sh");
		string comm = string("/home/pi/TinyLink_Config/wifi_config.sh ") + SSID + " " + PassW;
		int result = system(comm.c_str());
		if (-1 == result){
			perror("Error configuring! by fkb");
			exit(-1); 
		}
		else if( 127 == result ) {
			perror("Error calling /bin/sh! when configured by fkb");
			exit(-1);
		}
		else if ( 512 == result) {
			perror("Error excuting configuration script! by fkb");
			exit(-1);
		}
		else if( 0 != result) {
			perror("Error others causes! by fkb");
			exit(-1);
		}

		//sleep(3);
		// check whether already joined the wifi_network
		cout << "Success configurration\n";
		char buf[200];
		FILE* fp = popen("sudo iwconfig", "r");
		fgets(buf, sizeof(buf), fp);
		//cout << buf <<endl;
		pclose(fp);
		string str(buf, strlen(buf) - 1);
		int m = str.find("unassociated");
		if( -1 == m) {
			cout << "Success join the SSID"<<endl;
			return 1;
		}
		else {
			cout << "Failture to join the SSID and please check the passW!" << endl;
			return 0;
		}	

	}	

	bool Wifi_Network::join(const string& SSID, const string& PassW) {
		return join(SSID.c_str(), PassW.c_str());
	}	

	bool Wifi_Network::join(const String& SSID, const String& PassW) {
		return join(SSID.c_str(), PassW.c_str());
	}	
	

	bool Wifi_Network::disjoin(){
		int result = system("sudo connmanctl disable wifi");
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

	TL_HTTP& Wifi_Network::fetchHTTP() {
		static TL_HTTP http_client;
		return http_client;
	}
	TL_MQTT& Wifi_Network::fetchMQTT() {
		static TL_MQTT mqtt_client;
		return mqtt_client;
	}

}


tinylink::Wifi_Network TL_WiFi;

