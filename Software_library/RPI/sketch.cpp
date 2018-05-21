
#include "TL_Libraries.h"

double x,y,z;
void setup() {
	
}

void loop() {
	TL_Display.clear();
	TL_Display.show("Forward!\n");

	std::cout<<"Forward"<<endl;	
	TL_Car.moveForward();
	TL_Time.delayMillis(3000);
	TL_Car.stop();
	TL_Time.delayMillis(2000);

	TL_Display.clear();
        TL_Display.show("Back\n!");

	std::cout<<"Back"<<endl;
        TL_Car.moveBack();
        TL_Time.delayMillis(3000);
        TL_Car.stop();
        TL_Time.delayMillis(2000);

        std::cout<<"turnLeft"<<endl;
        TL_Car.turnLeft();
        TL_Time.delayMillis(3000);
        TL_Car.stop();
	TL_Time.delayMillis(2000);

	std::cout<<"turnRigth"<<endl;
        TL_Car.turnRight();
        TL_Time.delayMillis(3000);
        TL_Car.stop();
        TL_Time.delayMillis(2000);
	
}
