#include "Grove_HCHO_HCHO_BBB.h"

Grove_HCHO_HCHO_BBB::Grove_HCHO_HCHO_BBB(adcPin pin):Sensor(0.0), R0(36.89){
	_pin = pin;
}

int Grove_HCHO_HCHO_BBB::_read(){
    int sensorValue=analogRead(_pin);
    double Rs=(1023.0/sensorValue)-1;
    double ppm=pow(10.0,((log10(Rs/R0)-0.0827)/(-0.4807)));
    if(ppm>=0){
        _data = ppm;
        return 0;
    }else{
        return -1;
    }
}

#if TINYLINK_HCHO == GROVE_HCHO
	Grove_HCHO_HCHO_BBB TL_HCHO(HCHO_ANALOG);
#endif
