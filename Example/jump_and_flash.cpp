short x,y,z,prex,prey,prez;

void setup(){
	prex=0;
	prey=0;
	prez=0;
}

void loop(){
    TL_Accelerometer.read();
    x = TL_Accelerometer.data_x();
    y = TL_Accelerometer.data_y();
    z = TL_Accelerometer.data_z();
    //如果加速计读数发生变化,LED闪烁三次
    if(x != prex || y != prey || z != prez){
		for(int i = 0 ; i < 3 ; ++ i){
            TL_LED.turnOn();
            TL_Time.delayMillis(1000);
            TL_LED.turnOff();
            TL_Time.delayMillis(1000);
        }
    }
    prex = x;
    prey = y;
    prez = z;
}
