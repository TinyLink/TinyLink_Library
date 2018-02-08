#ifndef TL_CONFIG_H
#define TL_CONFIG_H

#include "TL_Device_ID.h"

#define PLATFORM 3
#define BOARD 1005

#define SERIAL BBB_SERIAL
#define TIME BBB_TIME
#define TIMER BBB_TIMER

#define LED BBB_LED

#define TEMPERATURE DHT22
#define TEMPERATURE_DIGITAL_OUTPUT P8_11
#define TEMPERATURE_DIGITAL_INPUT P8_13

#define LIGHT GROVE_LIGHT
#define LIGHT_ANALOG P9_40

#define WIFI WIFI_USB
/*




#define LED OUTLED
#define LED_DIGITAL_OUTPUT P8_12

#define PM25 SDS018
#define PM25_UART_TX P9_11
#define PM25_UART_RX P9_13

#define PM10 SDS018
#define PM10_UART_TX P9_11
#define PM10_UART_RX P9_13



#define HUMIDITY DHT22
#define HUMIDITY_DIGITAL_OUTPUT P8_11

#define GPS U_BLOX
#define GPS_UART_TX P9_22
#define GPS_UART_RX P9_21


#define STORAGE BBB_SD

#define SOIL_HUMIDITY SOIL_MOISTURE_ANALOG
#define SOIL_HUMIDITY_ANALOG P9_39

#define SOUND GROVE_SOUND
#define SOUND_ANALOG P9_37
*/


#endif
