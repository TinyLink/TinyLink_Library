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


#include <Arduino.h>
#include "SparkFunMiniMoto_BBB.h"

// The address of the part is set by a jumper on the board. 
//  See datasheet or schematic for details; default is 0xD0.
MiniMoto::MiniMoto(byte addr)
{
  _addr = addr;
  // This sets the bit rate of the bus; I want 100kHz. See the
  //  datasheet for details on how I came up with this value.
}

// Return the fault status of the DRV8830 chip. Also clears any existing faults.
byte MiniMoto::getFault()
{
  byte buffer = 0;
  byte clearFault = 0x80;
  I2CReadBytes(0x01, &buffer, 1);
  I2CWriteBytes(0x01, &clearFault, 1);
  return buffer;
}

// Send the drive command over I2C to the DRV8830 chip. Bits 7:2 are the speed
//  setting; range is 0-63. Bits 1:0 are the mode setting:
//  - 00 = HI-Z
//  - 01 = Reverse
//  - 10 = Forward
//  - 11 = H-H (brake)
void MiniMoto::drive(int speed)
{
  byte regValue = 0x80;             // Before we do anything, we'll want to
                                    //  clear the fault status. To do that
                                    //  write 0x80 to register 0x01 on the
                                    //  DRV8830.
  I2CWriteBytes(0x01, &regValue, 1); // Clear the fault status.
  regValue = (byte)abs(speed);      // Find the byte-ish abs value of the input
  if (regValue > 63) regValue = 63; // Cap the value at 63.
  regValue = regValue<<2;           // Left shift to make room for bits 1:0
  if (speed < 0) regValue |= 0x01;  // Set bits 1:0 based on sign of input.
  else if (speed == 0) regValue |= 0x03;
  else           regValue |= 0x02;
  
  I2CWriteBytes(0x00, &regValue, 1);  
}

// Private function that reads some number of bytes from the accelerometer.
void MiniMoto::I2CReadBytes(byte addr, byte *buffer, byte len)
{
  readBytes(_addr, addr, len, buffer);
}

void MiniMoto::I2CWriteBytes(byte addr, byte *buffer, byte len)
{
  writeBytes(_addr, addr, len, buffer);
}

int8_t MiniMoto::readBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t *data) {

    int8_t count = 0;

 
            for (uint8_t k = 0; k < length; k += 1) {
                Wire.beginTransmission(devAddr);
                Wire.write(regAddr);
                Wire.endTransmission();
                Wire.beginTransmission(devAddr);
                Wire.requestFrom(devAddr, (uint8_t)(length - k));
        
                for (; Wire.available() ; count++) {
                    data[count] = Wire.read();
                }
        
                Wire.endTransmission();
            }

    return count;
}


bool MiniMoto::writeBytes(uint8_t devAddr, uint8_t regAddr, uint8_t length, uint8_t* data) {
  
    uint8_t status = 0;


    Wire.beginTransmission(devAddr);
    Wire.write((uint8_t) regAddr); // send address

    for (uint8_t i = 0; i < length; i++) {
            Wire.write((uint8_t) data[i]);  
    }

    status = Wire.endTransmission();

    return status == 0;
}

