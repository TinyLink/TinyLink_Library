#include "Grove_Car_Car_LinkIt_One.h"


Grove_Car_Car_LinkIt_One::Grove_Car_Car_LinkIt_One():motor0(0x65),motor1(0x60),init(0)//CH1=motor1=left,CH2=motor2=right
{
}

void Grove_Car_Car_LinkIt_One::begin(){
    if(init==0){
        Wire.begin();
        init=1;
    }
}

void Grove_Car_Car_LinkIt_One::moveForward(){
    this->begin();
    motor0.drive(63);
    motor1.drive(63);
}

void Grove_Car_Car_LinkIt_One::moveBack(){
    this->begin();
    motor0.drive(-63);
    motor1.drive(-63);
}

void Grove_Car_Car_LinkIt_One::stop(){
    this->begin();
    motor0.drive(0);
    motor1.drive(0);
}

void Grove_Car_Car_LinkIt_One::turnLeft(){
    this->begin();
    motor0.drive(-63);
    motor1.drive(63);
}

void Grove_Car_Car_LinkIt_One::turnRight(){
    this->begin();
    motor0.drive(63);
    motor1.drive(-63);
}


Grove_Car_Car_LinkIt_One TL_Car;