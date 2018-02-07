#include "MAIN.h"
#include "Wiring.h"

void _setup() {
	#ifdef TIME
	tinylink::Time::initialiseEpoch();
	#endif
	#ifdef TIMER
	timer_initialize();
	#endif
}
void _cleanup() {
	#ifdef TIMER
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
