#include "Arduino.h"
#include <string.h>


void setup() {
}

/*
void loop() {
	TL_LED.turnOn();
	std::cout<<TL_LED.state()<<std::endl;
	TL_Time.delayMillis(1000);
	TL_LED.turnOff();
	std::cout<<TL_LED.state()<<std::endl;
	TL_Time.delayMillis(1000);
}
*/

void loop() {
	TL_Bulb.turnOn();
	std::cout<<TL_Bulb.state()<<std::endl;
	TL_Time.delayMillis(2000);
	TL_Bulb.turnOff();
	std::cout<<TL_Bulb.state()<<std::endl;
	TL_Time.delayMillis(2000);
}

/*
void loop() {
	TL_Temperature.read();
	TL_Humidity.read();
	std::cout<<TL_Temperature.data()<<std::endl;
	std::cout<<TL_Humidity.data()<<std::endl;
	TL_Time.delayMillis(1000);
}
*/
/*
void loop(){
	TL_Car.moveForward();
	TL_Time.delayMillis(1000);
	TL_Car.moveBack();
	TL_Time.delayMillis(1000);
	TL_Car.turnLeft();
	TL_Time.delayMillis(1000);
	TL_Car.turnRight();
	TL_Time.delayMillis(1000);
	TL_Car.stop();
	TL_Time.delayMillis(1000);
}
*/
/*
void loop(){
	TL_Soil_Humidity.read();
	cout<<TL_Soil_Humidity.data()<<endl;
	TL_Time.delayMillis(1000);
}
*/
/*
void loop(){
	TL_HCHO.read();
	cout<<TL_HCHO.data()<<endl;
	TL_Time.delayMillis(1000);
}
*/
/*
void loop(){
	TL_Display.show("123");
	TL_Time.delayMillis(1000);
	TL_Display.show("345");
	TL_Time.delayMillis(1000);
	TL_Display.clear();
	TL_Time.delayMillis(1000);
}
*/
/*
void loop() {
	TL_Light.read();
	std::cout<<TL_Light.data()<<std::endl;
	TL_Time.delayMillis(1000);
}
*/
/*
void loop() {
        TL_Motor.turnOn();
        std::cout<<TL_Motor.state()<<std::endl;
        TL_Time.delayMillis(5000);
        TL_Motor.turnOff();
        std::cout<<TL_Motor.state()<<std::endl;
        TL_Time.delayMillis(2000);
}
*/
/*
void loop() {
        TL_Skin_Current.read();
        double data=TL_Skin_Current.data();
        data=((1024+2*data)*10000)/(512-data);
        std::cout<<data<<std::endl;
        TL_Time.delayMillis(1000);
}
*/
/*
void loop() {
        int status=TL_Heart_Rate.read();
        double data=TL_Heart_Rate.data();
        std::cout<<data<<"?"<<status<<std::endl;
        TL_Time.delayMillis(1000);
}
*/
/*
void loop() {
          TL_Accelerometer.read();
          double dataX=TL_Accelerometer.data_x();
          double dataY=TL_Accelerometer.data_y();
          double dataZ=TL_Accelerometer.data_z();
      
          std::cout<<"X="<<dataX<<"\nY="<<dataY<<"\nZ="<<dataZ<<std::endl;
          TL_Time.delayMillis(1000);
}
*/
/*
void loop() {

	  int c = TL_Accelerometer.read();
 	  std::cout<<"c="<<c<<endl;
          double dataAX=TL_Accelerometer.data_x();
	  double dataAY=TL_Accelerometer.data_y();
	  double dataAZ=TL_Accelerometer.data_z();
      
          std::cout<<"AX="<<dataAX<<"\nAY="<<dataAY<<"\nAZ="<<dataAZ<<std::endl;
          //TL_Time.delayMillis(1000);
	 
	  int b =TL_Gyro.read();
	  std::cout<<"b="<<b<<endl;
          double dataGX=TL_Gyro.data_x();
	  double dataGY=TL_Gyro.data_y();
	  double dataGZ=TL_Gyro.data_z();
      
          std::cout<<"GX="<<dataGX<<"\nGY="<<dataGY<<"\nGZ="<<dataGZ<<std::endl;
          //TL_Time.delayMillis(1000);

          int a=TL_Magnet.read();
	  std::cout<<"a="<<a<<endl;
          double dataMX=TL_Magnet.data_x();
	  double dataMY=TL_Magnet.data_y();
	  double dataMZ=TL_Magnet.data_z();
      
          std::cout<<"MX="<<dataMX<<"\nMY="<<dataMY<<"\nMZ="<<dataMZ<<std::endl;
          TL_Time.delayMillis(1000);
}
*/
