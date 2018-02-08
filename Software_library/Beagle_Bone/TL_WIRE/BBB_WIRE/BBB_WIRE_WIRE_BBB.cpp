#include "BBB_WIRE_WIRE_BBB.h"

Wire_Network::Wire_Network(){
	//httpClient = new CLibcurl();
}

Wire_Network::~Wire_Network(){
	//delete httpClient;
}

bool Wire_Network::init() { return 1;} // dummy funtion

bool Wire_Network::setConfig(const char* IP, const char* netmask, const char* gateway, const char* dns_nameservers) {
	if ( !IP || !netmask || !gateway || !dns_nameservers){// judge whether ang
		printf(" Some configuration is null string!\n");
		exit(-1);
	}
	FILE *fp;
	char buf[200];
	fp = popen("sudo connmanctl services", "r");
	fgets(buf, sizeof(buf),fp);
	pclose(fp);
	// removing the ending '\n'
	string wire_str(buf, strlen(buf) - 1);
	int pos = wire_str.find("ethernet");
	if (-1 == pos){
		perror("Not insert the cable");
		exit(-1);
	}
	string cable_name = wire_str.substr(pos);
	string comm = string("sudo connmanctl config ") + cable_name + " --ipv4 manual " + IP + " " + netmask + " " + gateway + " --nameservers" + " " \
	+ dns_nameservers;

	// for(size_t i = 0 ; i != dns_nameservers.size(); i++){
	// 	comm = comm + " " + dns_nameservers[i];
	// }
	
	int result = system(comm.c_str());
	if (-1 == result){
		perror("Error configuring!");
		exit(-1); 
	}
	else if( 127 == result ) {
		perror("Error calling /bin/sh!");
		exit(-1);
	}
	else if ( 0 == result) {
		cout << "Suceess Configuration!" <<endl;
		return 1;
	}
	return 0;
}


bool Wire_Network::setConfig(const string& IP, const string& netmask, const string& gateway, const string& dns_nameservers){// call the Connman commond to configure
	return setConfig(IP.c_str(), netmask.c_str(), gateway.c_str(), dns_nameservers.c_str());
}


bool Wire_Network::setConfig(const String& IP, const String& netmask, const String& gateway, const String& dns_nameservers){// call the Connman commond to configure
	return setConfig(IP.c_str(), netmask.c_str(), gateway.c_str(), dns_nameservers.c_str());
}

bool Wire_Network::available(){
	return 1;
}


TL_HTTP Wire_Network::fetchHTTP() {
	TL_HTTP http_client;
	return http_client;
}
TL_MQTT Wire_Network::fetchMQTT() {
	TL_MQTT mqtt_client;
	return mqtt_client;
}

#if PLATFORM == 3 && BOARD == 1005
#if WIRE == BBB_WIRE
Wire_Network TL_WIRE;
#endif
#endif
