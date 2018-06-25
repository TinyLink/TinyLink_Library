#ifndef GROVE_CAR_CAR_ARDUINO_UNO_H
#define GROVE_CAR_CAR_ARDUINO_UNO_H


#include "TL_Config.h"
#include "SparkFunMiniMoto.h"


 class Grove_Car_Car_Arduino_UNO
  {
          public:
		  Grove_Car_Car_Arduino_UNO();//set i2c_slave address
		
		  void moveForward();
		  void moveBack();
		  void stop();
		  void turnLeft();//right wheel forward, left wheel backward
		  void turnRight();
		  
		  private:
		  MiniMoto motor0; 
    	  MiniMoto motor1;
     
  };

extern Grove_Car_Car_Arduino_UNO TL_Car;

#endif