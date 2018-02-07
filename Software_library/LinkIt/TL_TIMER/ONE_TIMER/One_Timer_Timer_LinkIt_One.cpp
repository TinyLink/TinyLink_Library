#include "One_Timer_Timer_LinkIt_One.h"

TLC_Timer::TLC_Timer(int tid)
{
  _tid = tid;
  void(*_callback)() = NULL;
  _freq = 0;
  _period = 0;
  _timerID = -1;
}

void createTimer(TLC_Timer* timer)
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

void TLC_Timer::attachInterrupt(void (*callback)())
{
  _callback = callback;
}

void TLC_Timer::detachInterrupt()
{
  return;
}

void TLC_Timer::setFrequency(unsigned long freq, int type)
{
  if (freq > 0)
  {
    _freq = freq;
    _period = 1000 / _freq;
  }
}

void TLC_Timer::setPeriod(unsigned long period, int type)
{
  if (period > 0)
  {
    _period = period;
  }
}

bool TLC_Timer::start()
{
  LTask.remoteCall((remote_call_ptr)createTimer, this);
  return true;
}

bool TLC_Timer::stop()
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

unsigned long TLC_Timer::getFrequency()
{
  return _freq;
}

unsigned long TLC_Timer::getPeriod()
{
  return _period;
}

VMINT TLC_Timer::getTimerID()
{
  return _timerID;
}

void TLC_Timer::setTimerID(VMINT timerID)
{
  _timerID = timerID;
}

VMINT TLC_Timer::getTID()
{
  return _tid;
}

TLC_Timer TL_Timer(0);
TLC_Timer TL_Timer1(1);
TLC_Timer TL_Timer2(2);
TLC_Timer TL_Timer3(3);
