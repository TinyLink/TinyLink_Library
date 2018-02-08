#include "OUTLED_LED_BBB.h"


OUT_LED::OUT_LED(Pin pin){ 
    this->pin = pin;
    status = 0;
}

void OUT_LED::turnOn(){ 
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
}

void OUT_LED::turnOff(){ 
    pinMode(pin, OUTPUT);
    digitalWrite(pin, LOW);
}

void OUT_LED::toggle(){
    bool state = digitalRead(pin);
    pinMode(pin, OUTPUT);
    digitalWrite(pin, !state);
}

bool OUT_LED::state(){
    return digitalRead(pin);
}

#if PLATFORM == 3 && BOARD == 1005
    #if LED == OUTLED
        #ifdef LED_DIGITAL_OUTPUT
            OUT_LED TL_LED(LED_DIGITAL_OUTPUT);
        #endif
    #endif
#endif