#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

// System library               --------------------------------------------------------------------
#ifdef TINYLINK_TIME
	#if TINYLINK_TIME == MBED_TIME
		#include "Mbed_Time_Time_Mbed.h"
	#endif
#endif

// Commuincation library        --------------------------------------------------------------------
#ifdef TINYLINK_BLUETOOTH
	#if TINYLINK_BLUETOOTH == MBED_BLUETOOTH
		#include "Mbed_Bluetooth_Bluetooth_Mbed.h"
	#endif
#endif

// Sensing library              --------------------------------------------------------------------
#ifdef TINYLINK_ACCELEROMETER
	#if TINYLINK_ACCELEROMETER == MBED_ACCELEROMETER
		#include "Mbed_Accelerometer_Accelerometer_Mbed.h"
	#endif
#endif

#ifdef TINYLINK_GYRO
	#if TINYLINK_GYRO == MBED_GYRO
		#include "Mbed_Gyro_Gyro_Mbed.h"
	#endif
#endif

// Control library              --------------------------------------------------------------------
#ifdef TINYLINK_LED
	#if TINYLINK_LED == MBED_LED
		#include "Mbed_Led_Led_Mbed.h"
	#endif
#endif

#endif
