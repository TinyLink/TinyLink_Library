#include "One_Timer_Timer_LinkIt_One.h"

One_Timer_Timer_LinkIt_One::One_Timer_Timer_LinkIt_One(int tid)
{
  _tid = tid;
  void(*_callback)() = NULL;
  _freq = 0;
  _period = 0;
  _timerID = -1;
}

void createTimer(One_Timer_Timer_LinkIt_One* timer)
{
  // vm_create_timer is defined vmtimer.h
  // VMINT vm_create_timer(VMUINT32 millisec, VM_TIMERPROC_T timerproc);
  // parameters are the milliseconds between timer callbacks
  // and the function to callback
  // vm_create_timer returns the id of the timer that the Linkit One system creates
  // it will be less than zero if the system could not create a timer
  // NOTE: there can be a max of 10 of these timers at any time

  VMINT timerID = vm_create_timer(timer->getPeriod(), (VM_TIMERPROC_T)(*(timer->_callback)));
  timer->setTimerID(timerID);
  if (timerID < 0){
    //Serial.println(String("Failed to create Timer") + (timer->getTID() == 0 ? "" : String(timer->getTID())) + "\n"); 
  }else {
    //Serial.println(String("Timer") + (timer->getTID() == 0 ? "" : String(timer->getTID())) + " is created\n");
  }
}

void One_Timer_Timer_LinkIt_One::attachInterrupt(void (*callback)())
{
  _callback = callback;
}

void One_Timer_Timer_LinkIt_One::detachInterrupt()
{
  return;
}

void One_Timer_Timer_LinkIt_One::setFrequency(unsigned long freq, int type)
{
  if (freq > 0)
  {
    _freq = freq;
    _period = 1000 / _freq;
  }
}

void One_Timer_Timer_LinkIt_One::setPeriod(unsigned long period, int type)
{
  if (period > 0)
  {
    _period = period;
  }
}

bool One_Timer_Timer_LinkIt_One::start()
{
  LTask.remoteCall((remote_call_ptr)createTimer, this);
  return true;
}

bool One_Timer_Timer_LinkIt_One::stop()
{
  if (_timerID >= 0)
  {
    VMINT res = vm_delete_timer(_timerID);
    return res == 0;
  }
  else
  {
    //Serial.println(String("Timer") + (_tid == 0 ? "" : String(_tid)) + " does not exist\n");
    return false;
  }
}

unsigned long One_Timer_Timer_LinkIt_One::getFrequency()
{
  return _freq;
}

unsigned long One_Timer_Timer_LinkIt_One::getPeriod()
{
  return _period;
}

VMINT One_Timer_Timer_LinkIt_One::getTimerID()
{
  return _timerID;
}

void One_Timer_Timer_LinkIt_One::setTimerID(VMINT timerID)
{
  _timerID = timerID;
}

VMINT One_Timer_Timer_LinkIt_One::getTID()
{
  return _tid;
}

One_Timer_Timer_LinkIt_One TL_Timer(0);
One_Timer_Timer_LinkIt_One TL_Timer1(1);
One_Timer_Timer_LinkIt_One TL_Timer2(2);
One_Timer_Timer_LinkIt_One TL_Timer3(3);
