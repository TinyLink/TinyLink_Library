void setup() {
}

void loop() {
    TL_LED.turnOn();
    TL_Time.delayMillis(1000);
    TL_LED.turnOff();
    TL_Time.delayMillis(1000);
}