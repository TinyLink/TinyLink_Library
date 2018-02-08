#include "MAIN.h"
#include "Wiring.h"

void _setup() {
	tinylink::Time::initialiseEpoch();
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
