#include "BBB_Time_Time_BBB.h"

void _TIME::delayMillis(uint32_t duration) {
	::delay(duration);
}

void _TIME::delayMicros(uint32_t duration) {
	::delayMicroseconds(duration);
}

uint32_t _TIME::millisFromStart() {
	return ::millis();
}

uint32_t _TIME::microsFromStart() {
	return ::micros();
}

/*string _TIME::timeFromInternet() {
	return ::timeFromInternet();
}

string _TIME::timeFromGPS() {
	return ::timeFromGPS();
}*/

_TIME TL_Time;
