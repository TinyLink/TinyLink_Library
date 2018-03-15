#include "Arduino_Timer_Timer_Arduino_UNO.h"

Arduino_Timer_Timer_Arduino_UNO::Arduino_Timer_Timer_Arduino_UNO(int tid)
{
  _tid = tid;
  state = -2;
}

void Arduino_Timer_Timer_Arduino_UNO::attachInterrupt(void (*callback)())
{
  if (_tid == 1)
  {
    Timer1.attachInterrupt(callback);
    state = -1;
  }
}

void Arduino_Timer_Timer_Arduino_UNO::detachInterrupt()
{
  if (_tid == 1)
  {
    Timer1.detachInterrupt();
  }
}

void Arduino_Timer_Timer_Arduino_UNO::setFrequency(unsigned long freq, int type)
{
  if (freq > 0)
  {
    _freq = freq;
    _period = 1000000/_freq;
  }
}

void Arduino_Timer_Timer_Arduino_UNO::setPeriod(unsigned long period, int type)
{
  if (period > 0)
  {
    _period = 1000*period;
  }
}

bool Arduino_Timer_Timer_Arduino_UNO::start()
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

bool Arduino_Timer_Timer_Arduino_UNO::stop()
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

unsigned long Arduino_Timer_Timer_Arduino_UNO::getFrequency()
{
  return _freq;
}

unsigned long Arduino_Timer_Timer_Arduino_UNO::getPeriod()
{
  return _period;
}

int Arduino_Timer_Timer_Arduino_UNO::getTID()
{
  return _tid;
}
Arduino_Timer_Timer_Arduino_UNO TL_Timer(1);
