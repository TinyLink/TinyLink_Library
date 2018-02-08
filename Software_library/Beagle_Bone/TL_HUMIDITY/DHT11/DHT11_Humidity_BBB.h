#ifndef DHT11_HUMIDITY_BBB_H
#define DHT11_HUMIDITY_BBB_H

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




typedef struct tag_DHT11_HUMIDITY_PIN
{
	int base;
	int num;
}DHT11_HUMIDITY_PIN;


class DHT11_HUMIDITY : public Sensor<double>
{
private:
	double tem;
	int type, gpio_base, gpio_num;
protected:
	int _read();
public:
	DHT11_HUMIDITY(int u_type);
};



#if PLATFORM == 3 && BOARD == 1005
#if HUMIDITY == DHT11
extern DHT11_HUMIDITY TL_Humidity;
#endif
#endif

#endif