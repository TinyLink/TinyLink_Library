#ifndef GROVE_SOUND_SOUND_BBB_H
#define GROVE_SOUND_SOUND_BBB_H

#include <iostream> 
#include <fstream> 
#include <string> 
#include <sstream>
#include <cstdio>
#include <pthread.h>

#include "ADC.h"
//#include "Read_Stream.h"
#include "TL_Config.h"
using namespace std;

class Grove_Sound_BBB : public ReadStream<double>
{
private:
	adcPin Grove_Sound_Pin;

protected:
	int readOnce();

public:
	Grove_Sound_BBB(adcPin pin);
};


#if PLATFORM == 3 && BOARD == 1005
#if SOUND == GROVE_SOUND
extern Grove_Sound_BBB TL_Sound;
#endif
#endif


#endif


