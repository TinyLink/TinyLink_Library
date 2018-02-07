#include "Arduino_Timer_Timer_Arduino_UNO.h"

TLC_Timer::TLC_Timer(int tid)
{
  _tid = tid;
  state = -2;
}

void TLC_Timer::attachInterrupt(void (*callback)())
{
  if (_tid == 1)
  {
    Timer1.attachInterrupt(callback);
    state = -1;
  }
}

void TLC_Timer::detachInterrupt()
{
  if (_tid == 1)
  {
    Timer1.detachInterrupt();
  }
}

void TLC_Timer::setFrequency(unsigned long freq, int type)
{
  if (freq > 0)
  {
    _freq = freq;
    _period = 1000000/_freq;
  }
}

void TLC_Timer::setPeriod(unsigned long period, int type)
{
  if (period > 0)
  {
    _period = 1000*period;
  }
}

bool TLC_Timer::start()
{
  if (_tid == 1)
  {
    if (state == -1)
    {
      Timer1.initialize(_period);
      state = 1;
    }
    if (state == 0)
    {
      Timer1.start();
      state = 1;
    }
  }
  return true;
}

bool TLC_Timer::stop()
{
  if (_tid == 1)
  {
    Timer1.stop();
    if (state > 0)
    {
      state = 0;
    }
  }
  return true;
}

unsigned long TLC_Timer::getFrequency()
{
  return _freq;
}

unsigned long TLC_Timer::getPeriod()
{
  return _period;
}

int TLC_Timer::getTID()
{
  return _tid;
}
TLC_Timer TL_Timer(1);
