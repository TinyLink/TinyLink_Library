#ifndef ONE_TIMER_TIMER_LINKIT_ONE_H
#define ONE_TIMER_TIMER_LINKIT_ONE_H

#include <Arduino.h>
#include "LTask.h"
#include "vmtimer.h"

#define TIMER_PERIODIC 1
#define TIMER_ONE_SHOT 0

class One_Timer_Timer_LinkIt_One {
private:
  int _tid;      //timer ID in TinyLink
  VMINT _timerID;    //timer ID in LinkIt One
  unsigned long _period;
  unsigned long _freq;
  // void createTimer(void);

public:
  void (*_callback)();
  One_Timer_Timer_LinkIt_One(int tid);
  void attachInterrupt(void (*callback)());
  void detachInterrupt();
  void setFrequency(unsigned long freq, int type = TIMER_PERIODIC);
  void setPeriod(unsigned long period, int type = TIMER_PERIODIC);
  bool start();
  bool stop();
  
  unsigned long getFrequency();
  unsigned long getPeriod();
  VMINT getTimerID();
  int getTID();
  void setTimerID(VMINT timerID);
};

extern One_Timer_Timer_LinkIt_One TL_Timer;
extern One_Timer_Timer_LinkIt_One TL_Timer1;
extern One_Timer_Timer_LinkIt_One TL_Timer2;
extern One_Timer_Timer_LinkIt_One TL_Timer3;

#endif
