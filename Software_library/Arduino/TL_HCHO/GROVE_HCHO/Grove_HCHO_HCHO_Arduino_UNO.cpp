#include "Grove_HCHO_HCHO_Arduino_UNO.h"
#include <math.h>

Grove_HCHO_HCHO_Arduino_UNO::Grove_HCHO_HCHO_Arduino_UNO():Sensor(0.0), R0(36.89){
}

int Grove_HCHO_HCHO_Arduino_UNO::_read(){
	int sensorValue=analogRead(A0);
    double Rs=(1023.0/sensorValue)-1;
    double ppm=pow(10.0,((log10(Rs/R0)-0.0827)/(-0.4807)));
    if(ppm>=0){
        _data = ppm;
        return 0;
    }else{
        return -1;
    }
}

Grove_HCHO_HCHO_Arduino_UNO TL_HCHO;