#ifndef BBBU_BLOX_H
#define BBBU_BLOX_H

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Sensor_template.h"
using namespace std;

namespace tinylink {
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
	

	class u_blox_GPS : public Sensor<gps_data>
	{
	private:
		int getComma(unsigned char num, char *str);
		double getDoubleNumber(char *s);
		int parse(char *gpsData);	

	protected:
		int _read();
	  
	public:
		u_blox_GPS();
	};
	void UTC2BTC(date_time *);

}
extern tinylink::u_blox_GPS TL_GPS;

#endif
