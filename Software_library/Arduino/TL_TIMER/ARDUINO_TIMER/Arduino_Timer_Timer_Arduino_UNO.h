#ifndef ARDUINO_TIMER_TIMER_ARDUINO_UNO_H
#define ARDUINO_TIMER_TIMER_ARDUINO_UNO_H

#include <Arduino.h>
#include "TimerOne.h"

#define TIMER_ONE_SHOT 0
#define TIMER_PERIODIC 1

class Arduino_Timer_Timer_Arduino_UNO {
private:
  int _tid;      //timer ID in TinyLink
  // VMINT _timerID;    //timer ID in LinkIt One
  unsigned long _period;
  unsigned long _freq;
  int state;

public:
  void (*_callback)();
  
  Arduino_Timer_Timer_Arduino_UNO(int tid);
  void attachInterrupt(void (*callback)());
  void detachInterrupt();
  void setFrequency(unsigned long freq, int type = TIMER_PERIODIC);
  void setPeriod(unsigned long period, int type = TIMER_PERIODIC);
  bool start();
  bool stop();
  
  unsigned long getFrequency();
  unsigned long getPeriod();
  // VMINT getTimerID();
  int getTID();
  // void setTimerID(VMINT timerID);};
};
extern Arduino_Timer_Timer_Arduino_UNO TL_Timer;

#endif
