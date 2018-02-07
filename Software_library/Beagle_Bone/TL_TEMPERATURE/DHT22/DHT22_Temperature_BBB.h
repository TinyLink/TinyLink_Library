#ifndef DHT22_TEMPERATURE_BBB_H
#define DHT22_TEMPERATURE_BBB_H

#include <stdio.h>
#include <errno.h>
#include <sched.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#include <iostream>
#include <pthread.h>
#include "Sensor_template.h"

#include "TL_Config.h"
#include "bbb_dht_read.h"
#include "bbb_mmio.h"
#include "common_dht_read.h"

using namespace std;




typedef struct tag_DHT22_TEMPERATURE_PIN
{
	int base;
	int num;
}DHT22_TEMPERATURE_PIN;


class DHT22_TEMPERATURE : public Sensor<double>
{
private:
	double hum;
	int type, gpio_base, gpio_num;
	
protected:
	int _read();

public:
	DHT22_TEMPERATURE(int u_type);
};

#if PLATFORM == 3 && BOARD == 1005
#if TEMPERATURE == DHT22
extern DHT22_TEMPERATURE TL_Temperature;
#endif
#endif

#endif