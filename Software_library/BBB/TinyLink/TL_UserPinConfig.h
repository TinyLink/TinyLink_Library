#ifndef TL_USERPINCONFIG_H
#define TL_USERPINCONFIG_H

#ifdef  P8_11_MODE
#undef  P8_11_MODE
#define P8_11_MODE gpio
#endif

#ifdef P9_18_MODE
#undef P9_18_MODE
#define P9_18_MODE gpio
#endif

#ifdef P9_17_MODE
#undef P9_17_MODE
#define P9_17_MODE gpio
#endif

#ifdef  P8_13_MODE
#undef  P8_13_MODE
#define P8_13_MODE gpio
#endif

#ifdef  P9_22_MODE
#undef  P9_22_MODE
#define P9_22_MODE gpio
#endif

#ifdef  P9_21_MODE
#undef  P9_21_MODE
#define P9_21_MODE gpio
#endif

/*
#ifdef  P8_12_MODE
#undef  P8_12_MODE
#define P8_12_MODE gpio
#endif

#ifdef  P9_11_MODE
#undef  P9_11_MODE
#define P9_11_MODE uart
#endif

#ifdef  P9_13_MODE
#undef  P9_13_MODE
#define P9_13_MODE uart
#endif

#ifdef 	SDS018_PM25_Serial
#undef	SDS018_PM25_Serial
#define SDS018_PM25_Serial TL_Serial2
#endif


#ifdef  P9_21_MODE
#undef  P9_21_MODE
#define P9_21_MODE uart
#endif

#ifdef  P9_22_MODE
#undef  P9_22_MODE
#define P9_22_MODE uart
#endif

#ifdef	U_BLOX_GPS_Serial
#undef	U_BLOX_GPS_Serial
#define U_BLOX_GPS_Serial TL_Serial1
#endif
*/

#endif
