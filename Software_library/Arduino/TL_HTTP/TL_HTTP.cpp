#include "TL_HTTP.h"

TL_HTTP::TL_HTTP():tcpClient(NULL){
#if WIFI == ESP8266
	if(tcpClient == NULL){
		tcpClient = new WiFiEspClient();
	}
#endif
}

TL_HTTP::TL_HTTP(const TL_HTTP& http):tcpClient(NULL){
#if WIFI == ESP8266
	if(tcpClient == NULL){
		tcpClient = new WiFiEspClient();
	}
#endif
}

TL_HTTP::~TL_HTTP(){
	if(tcpClient != NULL){
		delete tcpClient;
		tcpClient = NULL;
	}
}

TL_HTTP& TL_HTTP::operator=(const TL_HTTP& http){
#if WIFI == ESP8266
	if(tcpClient == NULL){
		tcpClient = new WiFiEspClient();
	}
#endif
	return *this;
}

bool TL_HTTP::parseURL(const char* url, char* host, char* para){
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


bool TL_HTTP::get(const String& url){
	char* _url = (char*)malloc(sizeof(char)*(url.length()+1));
	url.toCharArray(_url, url.length()+1);
	bool res = get(_url);
	free(_url);
	return res;
}

bool TL_HTTP::get(const char *url){
	char host[32], para[120];
	if (parseURL(url, host, para) == false){
		return false;
	}
	char paraStr[200];
	sprintf(paraStr,"GET %s HTTP/1.1\r\nHost:%s\r\n\r\n",para,host);
	if(!tcpClient->connected()){
		int res = tcpClient->connect(host, 80);
		if(!res){
			return false;
		}
	}
	tcpClient->print(paraStr);
	return true;
}

bool TL_HTTP::post(const String& url, const String& data){
	char* _url = (char*)malloc(sizeof(char)*(url.length()+1));
	url.toCharArray(_url, url.length()+1);
	char* _data = (char*)malloc(sizeof(char)*(data.length()+1));
	data.toCharArray(_data, data.length()+1);
	bool res = post(_url,_data);
	free(_url);
	free(_data);
	return res;
}

bool TL_HTTP::post(const char* url, const char* data){
	char host[32], para[120];
	if (parseURL(url, host, para) == false){
		return false;
	}
	char paraStr[200];
	sprintf(paraStr,"POST %s HTTP/1.1\r\nHost:%s\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length:%d\r\n\r\n%s\r\n\r\n",para,host,strlen(data),data);
	if(!tcpClient->connected()){
		int res = tcpClient->connect(host, 80);
		if(!res){
			return false;
		}
	}
	tcpClient->print(paraStr);
	return true;
}
