# include "u_blox_GPS_BBB.h"

u_blox::u_blox():Sensor({2017, 3, 29, 0, 0, 0, 0, 0, 'N', 'E'}){
}


int u_blox::getComma(unsigned char num, char* str){
	unsigned char i, j = 0;
	int len = strlen((char *)str);
	for(i = 0; i < len; i++){
		if(str[i] == ',')
			j++;
		if(j == num)
			return i + 1;
	}
	return 0;
}

double u_blox::getDoubleNumber(char *s){
	char buf[20];
	memset(buf, 0, 20);
	unsigned char i;
	double rev;
	i = getComma(1, s);
	i = i - 1;
	strncpy(buf, s, i);
	buf[i] = 0;
	rev = atof(buf);
	return rev;
}

void UTC2BTC(date_time *GPS_t){
//***************************************************
//如果秒号先出,再出时间数据,则将时间数据+1秒
	GPS_t->second++; //加一秒
	if(GPS_t->second>59){
		GPS_t->second=0;
		GPS_t->minute++;
		if(GPS_t->minute>59){
			GPS_t->minute=0;
			GPS_t->hour++;
		}
	}	

//***************************************************
	GPS_t->hour+=8;		//北京时间跟UTC时间相隔8小时
	if(GPS_t->hour>23)
	{
		GPS_t->hour-=24;
		GPS_t->day+=1;
		if(GPS_t->month==2 ||GPS_t->month==4 ||GPS_t->month==6 ||GPS_t->month==9 ||GPS_t->month==11 ){
			if(GPS_t->day>30){			//上述几个月份是30天每月，2月份还不足30
		   		GPS_t->day=1;
				GPS_t->month++;
			}
		}
		else{
			if(GPS_t->day>31){			//剩下的几个月份都是31天每月
		   		GPS_t->day=1;
				GPS_t->month++;
			}
		}
		if(GPS_t->year % 4 == 0 ){//
	   		if(GPS_t->day > 29 && GPS_t->month ==2){		//闰年的二月是29天
	   			GPS_t->day=1;
				GPS_t->month++;
			}
		}
		else{
	   		if(GPS_t->day>28 &&GPS_t->month ==2){		//其他的二月是28天每月
	   			GPS_t->day=1;
				GPS_t->month++;
			}
		}
		if(GPS_t->month>12){
			GPS_t->month-=12;
			GPS_t->year++;
		}		
	}
}

int u_blox::parse(char *gpsData){
	double latitude = 0;
	double longitude = 0;
	int tmp, checksum;
	if(gpsData[0] == '$')
	{
		tmp = getComma(1, gpsData);
		_data.DATE_TIME.hour     = (gpsData[tmp + 0] - '0') * 10 + (gpsData[tmp + 1] - '0');
		_data.DATE_TIME.minute   = (gpsData[tmp + 2] - '0') * 10 + (gpsData[tmp + 3] - '0');
		_data.DATE_TIME.second   = (gpsData[tmp + 4] - '0') * 10 + (gpsData[tmp + 5] - '0');

		tmp = getComma(9, gpsData);
		_data.DATE_TIME.day     = (gpsData[tmp+0]-'0')*10+(gpsData[tmp+1]-'0');  
		_data.DATE_TIME.month   = (gpsData[tmp+2]-'0')*10+(gpsData[tmp+3]-'0');  
		_data.DATE_TIME.year    = (gpsData[tmp+4]-'0')*10+(gpsData[tmp+5]-'0')+2000; 	
		//UTC2BTC(&DATE_TIME); // turn the time to east area area

		tmp = getComma(3, gpsData);
		latitude = getDoubleNumber(&gpsData[tmp]);
		tmp = getComma(5, gpsData);
		longitude = getDoubleNumber(&gpsData[tmp]);
		tmp = getComma(2, gpsData);
		checksum = gpsData[tmp];
		if (checksum == 'A')
		{
			if (latitude != 0 && longitude != 0)
			{
				_data.lat = latitude / 100;
				_data.NS =  gpsData[getComma(4, gpsData)];
				_data.lng = longitude / 100;
				_data.EW =  gpsData[getComma(6, gpsData)];
				#ifdef DEBUG
				cout << "GPS  reading success Time:"<<" "<<_data.DATE_TIME.year << "/"<<_data.DATE_TIME.month<<"/"<<_data.DATE_TIME.day <<" "<<_data.DATE_TIME.hour<< ":"<< _data.DATE_TIME.minute<<":"<<_data.DATE_TIME.second<<endl;
				cout << "latitude: " << _data.lat <<_data.NS<< "  longitude: " <<_data.lng <<_data.EW<<endl;
				#endif

			}
			return 0;
		}
		return -1;
	}
	return -1;
}


static char GPS_buff[GPS_DATA_SIZE] = "";


int u_blox::_read(){
	while(U_BLOX_GPS_Serial.available()){
		int GPS_flag = 0;
		char ch = U_BLOX_GPS_Serial.read();
		memset(GPS_buff, 0, sizeof(GPS_buff));
		if (ch == '$'){
			GPS_buff[0] = '$';
			while (U_BLOX_GPS_Serial.available() == -1);
			for(int i = 1; i < 6; i++){
				char ch2 = U_BLOX_GPS_Serial.read();
				GPS_buff[i] = ch2;
			}

			if (strncmp(GPS_buff + 1, "GPRMC", 5) == 0 ){
				while (U_BLOX_GPS_Serial.available() == -1);
				char *temp = GPS_buff + 6;
				while(U_BLOX_GPS_Serial.available()){
					char ch1 = U_BLOX_GPS_Serial.read();
					if (ch1 != '$') {
						*temp = ch1;
						temp ++;
						GPS_flag = 1;
					}
					else {
						U_BLOX_GPS_Serial.flush();
						break;
					}				
				}
			}
			if (GPS_flag == 1) {
				//cout << GPS_buff <<endl;
				parse(GPS_buff);
				return 0;
			}
		}
	}
	return -1;
}

/*double u_blox::lngData(){
	double temp;
	pthread_mutex_lock(&mutex_u_blox);
	temp = lng;
	pthread_mutex_unlock(&mutex_u_blox);
	return temp;
}

double u_blox::latData(){
	double temp;
	pthread_mutex_lock(&mutex_u_blox);
	temp = lat;
	pthread_mutex_unlock(&mutex_u_blox);
	return temp;
}

date_time u_blox::timeData(){
	date_time temp;
	pthread_mutex_lock(&mutex_u_blox);
	temp = DATE_TIME;
	pthread_mutex_unlock(&mutex_u_blox);
	return temp;
}*/


/*void* read_thread_u_blox(void* arg){
	pthread_detach(pthread_self());	
	u_blox* temp = (u_blox*) arg;
	//while(1)
	{
		temp->read_BL();
		#ifdef DEBUG
		printf("In thread ID = %lu \n", pthread_self());
		#endif
		pthread_exit(0);		
	}
}*/

#if PLATFORM == 3 && BOARD == 1005
#if GPS == U_BLOX
u_blox TL_GPS;
#endif
#endif
