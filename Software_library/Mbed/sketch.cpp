#include "TL_Libraries.h"
/*
#define UART_TX     p9
#define UART_RX     p11
Serial pc(UART_TX, UART_RX, 9600);
void setup(){
}

void loop(){
	pc.printf("%d\n", 231);
	pc.printf("ddd\n");
	TL_Time.delayMillis(1000);
}
*/

void setup(){
}

void loop(){
	TL_LED.toggle();
	TL_Time.delayMillis(1000);
}
