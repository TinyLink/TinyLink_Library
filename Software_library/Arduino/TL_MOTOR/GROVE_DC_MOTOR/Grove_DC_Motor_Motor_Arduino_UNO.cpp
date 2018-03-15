#include "Grove_DC_Motor_Motor_Arduino_UNO.h"

Grove_DC_Motor_Motor_Arduino_UNO::Grove_DC_Motor_Motor_Arduino_UNO():stateSig(0){
	pinMode(MOTOR_DIGITAL_OUTPUT, OUTPUT);
	digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
}

void Grove_DC_Motor_Motor_Arduino_UNO::turnOn(){
	digitalWrite(MOTOR_DIGITAL_OUTPUT, HIGH);
	stateSig = 1;
}

void Grove_DC_Motor_Motor_Arduino_UNO::turnOff(){
	digitalWrite(MOTOR_DIGITAL_OUTPUT, LOW);
	stateSig = 0;
}

const int Grove_DC_Motor_Motor_Arduino_UNO::state(){
	return stateSig;
}

Grove_DC_Motor_Motor_Arduino_UNO TL_Motor;
