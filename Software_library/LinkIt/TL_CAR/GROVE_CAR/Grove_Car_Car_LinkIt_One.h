#ifndef GROVE_CAR_CAR_LINKIT_ONE_H
#define GROVE_CAR_CAR_LINKIT_ONE_H


#include "TL_Config.h"
#include "SparkFunMiniMoto_LinkIt_One.h"
#include "Wire.h"

 class Grove_Car_Car_LinkIt_One
  {
          public:
		  Grove_Car_Car_LinkIt_One();//set i2c_slave address
		
		  void moveForward();
		  void moveBack();
		  void stop();
		  void turnLeft();//right wheel forward, left wheel backward
		  void turnRight();
		  
		  private:
		   MiniMoto motor0; 
    	   MiniMoto motor1;
		   int init;
		   void begin();
  };

extern Grove_Car_Car_LinkIt_One TL_Car;

#endif