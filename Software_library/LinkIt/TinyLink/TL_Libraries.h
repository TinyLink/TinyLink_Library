#ifndef TL_LIBRARIES_H
#define TL_LIBRARIES_H

#include "TL_Config.h"

// System library		--------------------------------------------------------------------
#ifdef SERIAL
	#if SERIAL == ONE_SERIAL
		#include "One_Serial_Serial_LinkIt_One.h"
	#endif
#endif

#ifdef TIME
	#if TIME == ONE_TIME
		#include "One_Time_Time_LinkIt_One.h"
	#endif
#endif

#ifdef TIMER
	#if TIMER == ONE_TIMER
		#include "One_Timer_Timer_LinkIt_One.h"
	#endif
#endif

#ifdef STORAGE
	#if STORAGE == ONE_SD
		#include "One_SD_Storage_LinkIt_One.h"
	#endif
#endif

// Commuincation library	--------------------------------------------------------------------
#ifdef BLUETOOTH
	#if BLUETOOTH == ONE_BLUETOOTH
		#include "One_Bluetooth_Bluetooth_LinkIt_One.h"
	#elif BLUETOOTH == DUAL_BLE
		#include "Dual_Ble_Bluetooth_Arduino_UNO.h"
	#endif
#endif

#ifdef WIFI
	#if WIFI == ESP8266
		#include "ESP8266_WiFi_LinkIt_One.h"
	#elif WIFI == ONE_WIFI
		#include "One_WiFi_WiFi_LinkIt_One.h"
	#endif
#endif

#ifdef GPRS
	// not available
#endif

// Sensing library		--------------------------------------------------------------------
#ifdef TEMPERATURE
	#if TEMPERATURE == DHT11
		#include "DHT11_Temperature_LinkIt_One.h"
	#endif
#endif

#ifdef HUMIDITY
	#if HUMIDITY == DHT11
		#include "DHT11_Humidity_LinkIt_One.h"
	#endif
#endif

#ifdef PM25
	#if PM25 == SDS018
		#include "SDS018_PM25_LinkIt_One.h"
	#endif
#endif

#ifdef LIGHT
	#if LIGHT == GROVE_LIGHT
		#include "Grove_Light_Light_LinkIt_One.h"
	#endif
#endif

#ifdef SOIL_HUMIDITY
	#if SOIL_HUMIDITY == SOIL_MOISTURE_ANALOG
		#include "Soil_Moisture_Analog_Soil_Humidity_LinkIt_One.h"
	#endif
#endif

#ifdef SOUND
	// not available
#endif

#ifdef ACCELEROMETER
	#if ACCELEROMETER == GROVE_IMU9
		#include "Grove_IMU9_Accelerometer_LinkIt_One.h"
	#endif
#endif

#ifdef GYRO
	#if GYRO == GROVE_IMU9
		#include "Grove_IMU9_Gyro_LinkIt_One.h"
	#endif
#endif

#ifdef MAGNET
	#if MAGNET == GROVE_IMU9
		#include "Grove_IMU9_Magnet_LinkIt_One.h"
	#endif
#endif

#ifdef GPS
	#if GPS == ONE_GPS
  		#include "One_GPS_GPS_LinkIt_One.h"
	#endif
#endif

// Control library		--------------------------------------------------------------------
#ifdef LED
	#if LED == ONE_LED
		#include "One_LED_LED_LinkIt_One.h"
	#endif
#endif

#ifdef MOTOR
	#if MOTOR == GROVE_DC_MOTOR
		#include "Grove_DC_Motor_Motor_LinkIt_One.h"
	#endif
#endif

#ifdef DISPLAY
	#if DISPLAY == GROVE_LCD_RGB
		#include "Grove_LCD_RGB_Display_LinkIt_One.h"
	#endif
#endif

#endif
