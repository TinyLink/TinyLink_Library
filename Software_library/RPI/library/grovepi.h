// Copyright Dexter Industries, 2016
// http://dexterindustries.com/grovepi

#ifndef GROVEPI_H
#define GROVEPI_H

#include <stdio.h>
#include <stdlib.h>

#include <fcntl.h>
#include <string.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <iostream>
#include <stdbool.h>
#include <stdint.h>
#include <stdexcept>
#include <time.h>

#include <linux/types.h>
#include <sys/ioctl.h>
#include <stddef.h>

// edited by fkb 17/6/13 <> --> ""
#include "i2c-dev.h"

using namespace std;

extern int fd;
extern char *fileName;
extern int  address;
extern unsigned char w_buf[5],r_buf[32];
extern unsigned long reg_addr;

#define OUTPUT 1
#define INPUT 0
#define HIGH 1
#define LOW 0

#define dRead_cmd 	1
#define dWrite_cmd 	2
#define aRead_cmd 	3
#define aWrite_cmd 	4
#define pMode_cmd	5
//Initialize
int init_dev(void);
//Initialize added by zjd
int initDevice(uint8_t address);

void SMBusName(char *smbus_name);

//Write a register
int write_block(char cmd,char v1,char v2,char v3);
//Read 1 byte of data
char read_byte(void);

// added by zjd
void delay(unsigned int milliseconds);
void pi_sleep(int); 
int analogRead(int pin);
int digitalWrite(int pin,int value);
int pinMode(int pin,int mode);
int digitalRead(int pin);
int analogWrite(int pin,int value);
pair<float, float> dht(int pin, int module);

// this class purpose is to give a more meaningful
  // description of problem that's encountered
  // and to redefine the function name for getting error details
  // (as suggested by Karan)
  class I2CError : public std::runtime_error
  {
          public:
                  explicit I2CError(const char *str) : std::runtime_error(str) {
                  }
                  const char* detail();
  };


#endif /*GROVEPI_H */
