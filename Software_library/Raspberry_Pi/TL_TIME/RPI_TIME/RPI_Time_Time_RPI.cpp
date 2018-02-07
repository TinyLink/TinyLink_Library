#include "RPI_Time_Time_RPI.h"
#include <cassert>
#include <sys/time.h>

namespace tinylink {

  Time::uint64_t Time::epochMilli = 0;
  Time::uint64_t Time::epochMicro = 0;  

  void Time::initialiseEpoch (void){
    struct timeval tv ; 

    gettimeofday (&tv, NULL) ;
    Time::epochMilli = (uint64_t)tv.tv_sec * (uint64_t)1000    + (uint64_t)(tv.tv_usec / 1000) ;
    Time::epochMicro = (uint64_t)tv.tv_sec * (uint64_t)1000000 + (uint64_t)(tv.tv_usec) ;
  }
  unsigned long Time::millisFromStart(void) {
    struct timeval tv ;
    uint64_t now ;  

    gettimeofday (&tv, NULL) ;
    now  = (uint64_t)tv.tv_sec * (uint64_t)1000 + (uint64_t)(tv.tv_usec / 1000) ; 

    return (uint32_t)(now - Time::epochMilli) ;
  }
  unsigned long Time::microsFromStart(void) {
    struct timeval tv ;
    uint64_t now ;  

    gettimeofday (&tv, NULL) ;
    now  = (uint64_t)tv.tv_sec * (uint64_t)1000000 + (uint64_t)tv.tv_usec ; 

    return (uint32_t)(now - Time::epochMicro) ;
  } 

  void Time::delayMillis(unsigned long howLong) {
    struct timespec sleeper, dummy ;  

    sleeper.tv_sec  = (time_t)(howLong / 1000) ;
    sleeper.tv_nsec = (long)(howLong % 1000) * 1000000 ;  

    nanosleep (&sleeper, &dummy) ;
  }
  void Time::delayMicros(unsigned long howLong) {
    struct timespec sleeper ;
    unsigned int uSecs = howLong % 1000000 ;
    unsigned int wSecs = howLong / 1000000 ;  

    if (howLong ==   0)
      return ;
    else if (howLong  < 100)
      _delayMicrosecondsHard (howLong) ;
    else
    {
      sleeper.tv_sec  = wSecs ;
      sleeper.tv_nsec = (long)(uSecs * 1000L) ;
      nanosleep (&sleeper, NULL) ;
    }
  }
  void Time::_delayMicrosecondsHard (unsigned int howLong)
  {
    struct timeval tNow, tLong, tEnd ;  

    gettimeofday (&tNow, NULL) ;
    tLong.tv_sec  = howLong / 1000000 ;
    tLong.tv_usec = howLong % 1000000 ;
    timeradd (&tNow, &tLong, &tEnd) ; 

    while (timercmp (&tNow, &tEnd, <))
      gettimeofday (&tNow, NULL) ;
  } 

  string Time::timeFromInternet(void) {
  	//TODO: need network
  	//How to determine which module, wifi, gprs, to use?
  } 

  //TODO:
  string Time::timeFromGPS(void) {
  	
  }
}

tinylink::Time TL_Time;
