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

#include "Wiring.h"

#include "MAIN.h"

int main()
{
  //edited by fkb 16/12/6
  //initialize_loop();
  signal(SIGINT, StopProgram);
  
  #ifdef TINYLINK_TIMER
  timer_initialize();
  #endif

  #if (P9_21_MODE == uart) || (P9_22_MODE == uart)
  TL_Serial1.begin(9600);
  #endif 

  #if (P9_11_MODE == uart) || (P9_13_MODE == uart)
  TL_Serial2.begin(9600);
  #endif

  #if (P8_37_MODE == uart) || (P8_38_MODE == uart)
  TL_Serial3.begin(9600);
  #endif

  setup();

  while(!stop)
  {
    loop();
  }
  
  #ifdef TINYLINK_TIMER
  timer_finalize();
  #endif

  while(!stop)
  {
  }
  return 0;
}
