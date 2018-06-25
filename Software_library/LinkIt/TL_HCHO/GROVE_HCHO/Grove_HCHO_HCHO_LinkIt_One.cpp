#include "Grove_HCHO_HCHO_LinkIt_One.h"
#include <math.h>

Grove_HCHO_HCHO_LinkIt_One::Grove_HCHO_HCHO_LinkIt_One():Sensor(0.0), R0(36.89){
}

int Grove_HCHO_HCHO_LinkIt_One::_read(){
	int sensorValue=analogRead(HCHO_ANALOG);
    double Rs=(1023.0/sensorValue)-1;
    double ppm=pow(10.0,((log10(Rs/R0)-0.0827)/(-0.4807)));
    if(ppm>=0){
        _data = ppm;
        return 0;
    }else{
        return -1;
    }
}

Grove_HCHO_HCHO_LinkIt_One TL_HCHO;