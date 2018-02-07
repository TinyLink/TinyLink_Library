#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

// System library               --------------------------------------------------------------------
#ifdef TIME
	#if TIME == MBED_TIME
		#include "Mbed_Time_Time_Mbed.h"
	#endif
#endif

// Commuincation library        --------------------------------------------------------------------
#ifdef BLUETOOTH
	#if BLUETOOTH == MBED_BLUETOOTH
		#include "Mbed_Bluetooth_Bluetooth_Mbed.h"
	#endif
#endif

// Sensing library              --------------------------------------------------------------------
#ifdef ACCELEROMETER
	#if ACCELEROMETER == MBED_ACCELEROMETER
		#include "Mbed_Accelerometer_Accelerometer_Mbed.h"
	#endif
#endif

#ifdef GYRO
	#if GYRO == MBED_GYRO
		#include "Mbed_Gyro_Gyro_Mbed.h"
	#endif
#endif

// Control library              --------------------------------------------------------------------
#ifdef LED
	#if LED == MBED_LED
		#include "Mbed_Led_Led_Mbed.h"
	#endif
#endif

#endif
