/****************************************************************
Example code demonstrating the use of the Arduino Library for
the SparkFun MiniMoto board, which uses the TI DRV8830 IC for I2C
low-voltage DC motor control.

This code is beerware; if you use it, please buy me (or any other
SparkFun employee) a cold beverage next time you run into one of
us at the local.

17 Sep 2013- Mike Hord, SparkFun Electronics

Code developed in Arduino 1.0.5, on a Fio classic board.

**Updated for Arduino 1.6.4 5/2015**
****************************************************************/


#ifndef SparkFunMiniMoto_LinkIt_One_h
#define SparkFunMiniMoto_LinkIt_One_h

#include <Arduino.h>

// Fault constants
#define FAULT 0x01
#define ILIMIT 0x10
#define OTS 0x08
#define UVLO 0x04
#define OCP 0x02

class MiniMoto
{
  public:
    MiniMoto(byte addr);
    void drive(int speed);
    byte getFault();
  private:
    void I2CWriteBytes(byte addr, byte *buffer, byte len);
    void I2CReadBytes(byte addr, byte *buffer, byte len);
    byte _addr;
};

#endif