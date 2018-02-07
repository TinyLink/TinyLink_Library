#ifndef RPI_TIME_TIME_RPI_H
#define RPI_TIME_TIME_RPI_H

#include <string>
using std::string;

namespace tinylink {
    class Time {
    private:
        typedef unsigned long uint64_t;
        typedef unsigned int uint32_t;
    	static uint64_t epochMilli, epochMicro;
    	void _delayMicrosecondsHard (unsigned int howLong);
    public:
    	static void initialiseEpoch(void);
        static unsigned long millisFromStart(void);
        static unsigned long microsFromStart(void);
        
        void delayMillis(unsigned long ms);
        void delayMicros(unsigned long ms);
    	
        
        string timeFromInternet(void);
        string timeFromGPS(void);
    };
}

extern tinylink::Time TL_Time;

#endif
