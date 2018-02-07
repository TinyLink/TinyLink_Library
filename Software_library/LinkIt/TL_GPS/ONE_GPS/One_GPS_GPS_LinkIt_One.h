#ifndef ONE_GPS_GPS_LINKIT_ONE_H
#define ONE_GPS_GPS_LINKIT_ONE_H

// #include <Arduino.h>
#include <LGPS.h>
#include "TL_Config.h"

// typedef struct{
  // int year;
  // int month;
  // int day;
  // int hour;
  // int minute;
  // int second;
// } date_time;

class Built_In_GPS
{
  
private:
  double lng, lat;
  // date_time dt;
  gpsSentenceInfoStruct info;
  // char buff[256];
  
  static unsigned char getComma(unsigned char num,const char *str);
  static double getDoubleNumber(const char *s);
  static double getIntNumber(const char *s);
  void parseGPGGA(const char* GPGGAstr);
  
public:
  Built_In_GPS();
  void read();
  // date_time timeData();
  double lngData();
  double latData();
};

extern Built_In_GPS TL_GPS;

#endif
