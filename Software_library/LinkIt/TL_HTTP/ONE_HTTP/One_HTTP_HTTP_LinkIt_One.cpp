#include "One_HTTP_HTTP_LinkIt_One.h"

TL_HTTP::TL_HTTP():tcpClient(NULL){
#if TINYLINK_WIFI == ONE_WIFI
	if(tcpClient == NULL){
		tcpClient = new LWiFiClient();
	}
#endif
}

TL_HTTP::TL_HTTP(const TL_HTTP& http):tcpClient(NULL){
#if TINYLINK_WIFI == ONE_WIFI
	if(tcpClient == NULL){
		tcpClient = new LWiFiClient();
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
#if TINYLINK_WIFI == ONE_WIFI
	if(tcpClient == NULL){
		tcpClient = new LWiFiClient();
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
	char host[32], para[200];
	if (parseURL(url, host, para) == false){		
		return false;
	}
	unsigned long start = millis();
	while (0 == tcpClient->connect(host, 80) && millis() - start < 2000){
		delay(200);
	}
	tcpClient->println(String("GET ") + para + " HTTP/1.0");
	tcpClient->println("User-Agent: Wget/1.11.4");
  	tcpClient->println("Accept: */*");
  	tcpClient->println(String("Host: ") +host);
  	tcpClient->println("Connection: Close");
  	tcpClient->println();
	int peekByte = -1;
	start = millis();
	while (peekByte == -1 && tcpClient->connected() && millis() - start < 1000){
    		peekByte = tcpClient->peek();
    		delay(200);
  	}
	if(peekByte == -1){
		return false;
	}
	int lineFeedCount = 0;
	start = millis();
	while (lineFeedCount < 2 && millis() - start < 500){
		int value = tcpClient->read();
    		if (value == -1){
      			delay(10);
      			continue;
    		}
    		if (value == '\r'){
      			value = -1;
      			while (value == -1){
        			value = tcpClient->read();
			}
			if (value == '\n'){
				lineFeedCount++;
			}else{
				lineFeedCount = 0;
			}
		}else{
			lineFeedCount = 0;
		}
	}
	if(lineFeedCount < 2){
		return false;	
	}
	start = millis();
	char* val = (char*)malloc(sizeof(char)*50);
	strcpy(val,"NULL");
	int  i = 0;
	while (tcpClient->connected() && millis() - start < 1000){
    		val[i] = tcpClient->read();
    		i++;
  	}
	if(strcmp(val,"NULL")!=0){
		free(val);
		return true;
	}else{
		free(val);
		return false;
	}
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
	char host[32], para[200];
	if (parseURL(url, host, para) == false){
		return false;
	}
	unsigned long start = millis();
	while (0 == tcpClient->connect(host, 80) && millis() - start < 2000){
		delay(200);
	}
	tcpClient->println(String("POST ") + para + " HTTP/1.0");
	//tcpClient->println("User-Agent: Wget/1.11.4");
  	//tcpClient->println("Accept: */*");
	tcpClient->println(String("Host: ") +host);
	tcpClient->println("Content-Type: application/x-www-form-urlencoded");
	tcpClient->println(String("Content-Length: ")+strlen(data));
	tcpClient->println();
	tcpClient->println(data);
  	//tcpClient->println("Connection: Close");
  	tcpClient->println();
	int peekByte = -1;
	start = millis();
	while (peekByte == -1 && tcpClient->connected() && millis() - start < 1000){
    		peekByte = tcpClient->peek();
    		delay(200);
  	}
	if(peekByte == -1){
		return false;
	}
	int lineFeedCount = 0;
	start = millis();
	while (lineFeedCount < 2 && millis() - start < 500){
		int value = tcpClient->read();
    		if (value == -1){
      			delay(10);
      			continue;
    		}
    		if (value == '\r'){
      			value = -1;
      			while (value == -1){
        			value = tcpClient->read();
			}
			if (value == '\n'){
				lineFeedCount++;
			}else{
				lineFeedCount = 0;
			}
		}else{
			lineFeedCount = 0;
		}
	}
	if(lineFeedCount < 2){
		return false;	
	}
	start = millis();
	char* val = (char*)malloc(sizeof(char)*50);
	strcpy(val,"NULL");
	int  i = 0;
	while (tcpClient->connected() && millis() - start < 1000){
    		val[i] = tcpClient->read();
    		i++;
  	}
	if(strcmp(val,"NULL")!=0){
		free(val);
		return true;
	}else{
		free(val);
		return false;
	}
}
