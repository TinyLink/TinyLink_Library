#ifndef BBB_TIMER_TIMER_BBB_H
#define BBB_TIMER_TIMER_BBB_H

#include <cstdio>
#include <cstdlib>
#include <iostream>

using namespace std;
// 1000 -> 100 edited by fkb 16/12/14
#define MAX_TIMER_COUNT 100

typedef void (*timer_handler)();
typedef void (*timer_handler_stream)(void * user_data);

//typedef void (*timer_handler_no)();

//typedef void (*timer_handler)();

/*typedef enum {
	TIMER_ONE_SHOT = 0,
	TIMER_PERIODIC
} timer_Type;
*/
#define TIMER_ONE_SHOT 0
#define TIMER_PERIODIC 1

struct timer_node
{
    long                 fd;
    timer_handler        callback;
    timer_handler_stream        callback_stream;
    void *              user_data;
    unsigned int        interval; 
    int              type;
    struct timer_node * next;
};

class BTimer {
private:
    int start_flag; // indicate whether the the timer starts
    int interval_num; // for further usage
    struct timer_node * new_node;
    struct itimerspec new_value;
public:
	BTimer(); // internal defaults to 2s, type defaults to 
	BTimer(unsigned int interval, timer_handler handler, timer_handler_stream handler_stream, int type = TIMER_PERIODIC, void * user_data = NULL);
	~BTimer();
	BTimer& attachInterrupt(timer_handler handler);
	BTimer& attachInterrupt_stream(timer_handler_stream handler, void *user_data = NULL);

	BTimer& detachInterrupt();
	BTimer& detachInterrupt_stream();

	//BTimer& setOneShot();
	//BTimer& setPeriodic();
	BTimer& setPeriod(unsigned int interval, int type = TIMER_PERIODIC);
	BTimer& setPeriod_us(unsigned int interval, int type = TIMER_PERIODIC);
	BTimer& setFrequency(unsigned int frep, int type = TIMER_PERIODIC);
	bool start();
	bool stop();
};

int timer_initialize();
void timer_finalize();
struct timer_node * _get_timer_from_fd(int fd);

//#ifdef B_TIMER
extern BTimer TL_Timer;
//#endif

//#ifdef B_TIMER1
extern BTimer TL_Timer1;
//#endif

//#ifdef B_TIMER2
extern BTimer TL_Timer2;
//#endif

//#ifdef B_TIMER3
extern BTimer TL_Timer3;
//#endif

//#ifdef B_TIMER4
extern BTimer TL_Timer4;
//#endif

//#ifdef B_TIMER5
extern BTimer TL_Timer5;
//#endif

//#ifdef B_TIMER6
extern BTimer TL_Timer6;
//#endif

//#ifdef B_TIMER7
extern BTimer TL_Timer7;
//#endif

#endif
