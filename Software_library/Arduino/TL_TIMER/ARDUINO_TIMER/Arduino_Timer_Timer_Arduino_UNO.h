#ifndef ARDUINO_TIMER_TIMER_ARDUINO_UNO_H
#define ARDUINO_TIMER_TIMER_ARDUINO_UNO_H

#include <Arduino.h>
#include "TimerOne.h"

#define TIMER_ONE_SHOT 0
#define TIMER_PERIODIC 1

class TLC_Timer {
private:
  int _tid;      //timer ID in TinyLink
  // VMINT _timerID;    //timer ID in LinkIt One
  unsigned long _period;
  unsigned long _freq;
  int state;

public:
  void (*_callback)();
  
  TLC_Timer(int tid);
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
extern TLC_Timer TL_Timer;

#endif
