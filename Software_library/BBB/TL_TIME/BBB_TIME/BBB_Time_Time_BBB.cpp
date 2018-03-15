#include "BBB_Time_Time_BBB.h"

void BBB_Time_Time_BBB::delayMillis(uint32_t duration) {
	::delay(duration);
}

void BBB_Time_Time_BBB::delayMicros(uint32_t duration) {
	::delayMicroseconds(duration);
}

uint32_t BBB_Time_Time_BBB::millisFromStart() {
	return ::millis();
}

uint32_t BBB_Time_Time_BBB::microsFromStart() {
	return ::micros();
}

/*string BBB_Time_Time_BBB::timeFromInternet() {
	return ::timeFromInternet();
}

string BBB_Time_Time_BBB::timeFromGPS() {
	return ::timeFromGPS();
}*/

BBB_Time_Time_BBB TL_Time;
