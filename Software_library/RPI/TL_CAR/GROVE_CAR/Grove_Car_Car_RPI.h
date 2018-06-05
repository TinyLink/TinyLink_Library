#ifndef GROVE_DC_MOTOR_MOTOR_RPI_H
#define GROVE_DC_MOTOR_MOTOR_RPI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <string.h>
//#include <linux/i2c-dev.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdbool.h>
#include <stdint.h>

#include "grovepi.h"
#include "WString.h"

namespace tinylink
{
  class Grove_Car_Car_RPI
  {
          public:

                  Grove_Car_Car_RPI();//set i2c_slave address
		
	 	  void moveForward();
		  void moveBack();
		  void stop();
		  void turnLeft();//right wheel forward, left wheel stop
		  void turnRight();

                 

          private:

                  void sendCommand(uint8_t reg_addr, uint8_t value);
                  void selectSlave(uint8_t slave);
		  void Left_Motor(int speed);
                  void Right_Motor(int speed);
                  
		  uint8_t DEVICE_FILE;
                  uint8_t MOTOR_LEFT_ADDR;
                  uint8_t MOTOR_RIGHT_ADDR;
              
  };
}

extern tinylink::Grove_Car_Car_RPI TL_Car;

#endif

