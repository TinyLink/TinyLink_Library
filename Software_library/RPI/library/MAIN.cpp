#include "MAIN.h"
#include "Wiring.h"

void _setup() {
#ifdef TINYLINK_TIME
	tinylink::Time::initialiseEpoch();
#endif
#ifdef TINYLINK_TIMER
	timer_initialize();
#endif
}
void _cleanup() {
#ifdef TINYLINK_TIMER
	timer_finalize();
#endif
}
int main() {
	_setup();
	setup();
	while (1) loop();
	_cleanup();
	return 0;
}
