#include "Arduino.h"

void setup() {
}

void loop() {
	TL_Temperature.read();
	TL_Time.delayMillis(1000);
	cout<<TL_Temperature.data()<<endl;
	TL_Time.delayMillis(1000);
}

/*
void loop() {

          int a=TL_Magnet.read();
	  std::cout<<"a="<<a<<endl;
          double dataMX=TL_Magnet.data_x();
	  double dataMY=TL_Magnet.data_y();
	  double dataMZ=TL_Magnet.data_z();
      
          std::cout<<"MX="<<dataMX<<"\nMY="<<dataMY<<"\nMZ="<<dataMZ<<std::endl;
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
/*
void loop() {
	  std::cout<<"hello world!"<<std::endl;
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
	std::cout<<"hello world!"<<std::endl;

	TL_Temperature.read();
	std::cout<<"Temperature="<<TL_Temperature.data()<<endl;
	TL_Time.delayMillis(1000);

	TL_Humidity.read();
	cout<<"Humidity="<<TL_Humidity.data()<<endl;
	TL_Time.delayMillis(1000);
}
*/
/*
void loop(){
	TL_Display.show("Hellow");
	TL_Time.delayMillis(1000);
	TL_Display.show("csp");
	TL_Time.delayMillis(1000);
	TL_Display.clear();
	TL_Time.delayMillis(1000);
}
*/
/*
void loop(){
	TL_Car.moveForward();
	TL_Time.delayMillis(3000);
	TL_Car.moveBack();
	TL_Time.delayMillis(3000);
	TL_Car.turnLeft();
	TL_Time.delayMillis(3000);
	TL_Car.turnRight();
	TL_Time.delayMillis(3000);
	TL_Car.stop();
	TL_Time.delayMillis(3000);
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
	TL_Heart_Rate.read();
	std::cout<<TL_Heart_Rate.data()<<std::endl;
	TL_Time.delayMillis(1000);
}
*/

