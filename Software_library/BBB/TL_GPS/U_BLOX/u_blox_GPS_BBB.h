#ifndef U_BLOX_GPS_BBB_H
#define U_BLOX_GPS_BBB_H

#ifndef U_BLOX_GPS_Serial
#define U_BLOX_GPS_Serial TL_Serial
#endif

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "UART.h"
#include "Sensor_template.h"
#include "TL_Config.h"
using namespace std;



#define GPS_DATA_SIZE 101

typedef struct{
	int year;  
	int month; 
	int day;
	int hour;
	int minute;
	int second;
}date_time;

typedef struct {
	date_time DATE_TIME;
	double lng, lat;
	char NS, EW;
}gps_data;


class u_blox : public Sensor<gps_data>
{
private:
	int getComma(unsigned char num, char *str);
	double getDoubleNumber(char *s);
	int parse(char *gpsData);

protected:
	int _read();
  
public:
	u_blox();
};

#if PLATFORM == 3 && BOARD == 1005
#if TINYLINK_GPS == U_BLOX
extern u_blox TL_GPS;
#endif
#endif

void UTC2BTC(date_time *);

#endif
