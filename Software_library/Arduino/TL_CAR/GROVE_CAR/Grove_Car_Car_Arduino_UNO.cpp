#include "Grove_Car_Car_Arduino_UNO.h"

Grove_Car_Car_Arduino_UNO::Grove_Car_Car_Arduino_UNO():motor0(0xCA),motor1(0xC0)//CH1=motor1=left,CH2=motor2=right
{
}

void Grove_Car_Car_Arduino_UNO::moveForward(){
    motor0.drive(63);
    motor1.drive(63);
}

void Grove_Car_Car_Arduino_UNO::moveBack(){
    motor0.drive(-63);
    motor1.drive(-63);
}

void Grove_Car_Car_Arduino_UNO::stop(){
    motor0.drive(0);
    motor1.drive(0);
}

void Grove_Car_Car_Arduino_UNO::turnLeft(){
    motor0.drive(-63);
    motor1.drive(63);
}

void Grove_Car_Car_Arduino_UNO::turnRight(){
    motor0.drive(63);
    motor1.drive(-63);
}


Grove_Car_Car_Arduino_UNO TL_Car;