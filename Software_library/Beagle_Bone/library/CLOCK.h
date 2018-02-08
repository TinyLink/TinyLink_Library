/*
    This file is a part of the wiringBone library
    Copyright (C) 2015 Abhraneel Bera

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 3 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301
    USA
*/

#ifndef CLOCK_H
#define CLOCK_H

#include <iostream>
#include <sys/time.h>
#include <stdint.h>
#include <cstring>
#include <string>
#include "TL_Config.h"

using namespace std;

void startClock();
void delay(uint32_t duration);
void delayMicroseconds(uint32_t duration);
uint32_t millis();
uint32_t micros();

//added by fkb 16/11/22
void delayMillis(uint32_t duration);
void delayMicros(uint32_t duration);
uint32_t millisFromStart();
uint32_t microsFromStart();


/*string timeFromInternet();
string tl_time_Int2String(int value);
string timeFromGPS();*/

#endif 
