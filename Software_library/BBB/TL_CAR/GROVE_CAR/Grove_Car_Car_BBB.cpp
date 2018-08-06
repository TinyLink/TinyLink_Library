#include "Grove_Car_Car_BBB.h"


Grove_Car_Car_BBB::Grove_Car_Car_BBB():motor0(0x65),motor1(0x60),init(0)//CH1=motor1=left,CH2=motor2=right
{
}

void Grove_Car_Car_BBB::begin(){
    if(init==0){
        Wire.begin();
        init=1;
    }
}

void Grove_Car_Car_BBB::moveForward(){
    this->begin();
    motor0.drive(63);
    motor1.drive(63);
}

void Grove_Car_Car_BBB::moveBack(){
    this->begin();
    motor0.drive(-63);
    motor1.drive(-63);
}

void Grove_Car_Car_BBB::stop(){
    this->begin();
    motor0.drive(0);
    motor1.drive(0);
}

void Grove_Car_Car_BBB::turnLeft(){
    this->begin();
    motor0.drive(-63);
    motor1.drive(63);
}

void Grove_Car_Car_BBB::turnRight(){
    this->begin();
    motor0.drive(63);
    motor1.drive(-63);
}


Grove_Car_Car_BBB TL_Car;
