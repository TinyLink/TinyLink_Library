#include "Grove_HCHO_HCHO_RPI.h"
#include <math.h>
#include "TL_Config.h"

Grove_HCHO_HCHO_RPI::Grove_HCHO_HCHO_RPI(int pin):Sensor(0.0), R0(36.89), _pin(pin){
	if (init_dev() == -1) exit(1);
}

int Grove_HCHO_HCHO_RPI::_read(){
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
	Grove_HCHO_HCHO_RPI TL_HCHO(HCHO_ANALOG);
#endif
