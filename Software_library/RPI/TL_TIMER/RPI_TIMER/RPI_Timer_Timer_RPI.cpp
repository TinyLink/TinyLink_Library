#include <stdint.h>
#include <string.h>
#include <sys/timerfd.h>
#include <pthread.h>
#include <poll.h>
#include <stdio.h>
#include <unistd.h>

#include "RPI_Timer_Timer_RPI.h"

static void * _timer_thread(void * data);
static pthread_t tid_timer;
static struct timer_node *g_head = NULL;

int timer_initialize() {
    if ( pthread_create(&tid_timer, NULL, _timer_thread, NULL) ) {
        printf("RTimer: pthread creat error by fkb \n");
        return 0;
    }
    return 1;
}

RTimer::RTimer(): start_flag(0), interval_num(2000) {
    new_node = (struct timer_node *)malloc(sizeof(struct timer_node));

    if (new_node == NULL) {
        printf("RTimer: malloc memory error by fkb \n");
        exit(-1);
    }
    new_node->fd        = -101;
    new_node->callback  = NULL;
    new_node->callback_stream = NULL;
    new_node->user_data = NULL;
    new_node->interval  = interval_num;
    new_node->type      = TIMER_PERIODIC; 
    // set interval
    new_value.it_value.tv_sec  = new_node->interval / 1000;// unit microSecond
    new_value.it_value.tv_nsec = (new_node->interval % 1000) * 1000000;
    
    if (new_node->type == TIMER_PERIODIC)
    {
        new_value.it_interval.tv_sec = new_node->interval / 1000;// unit microSecond
        new_value.it_interval.tv_nsec = (new_node->interval % 1000) * 1000000;
    }
    else if (new_node->type == TIMER_ONE_SHOT)
    {
        new_value.it_interval.tv_sec = 0;
        new_value.it_interval.tv_nsec = 0;
    }
}

RTimer::RTimer(unsigned int interval, timer_handler handler, timer_handler_stream handler_stream, int type, void * user_data) : start_flag(0), interval_num(interval) {//interval_num(2000)
    new_node = (struct timer_node *)malloc(sizeof(struct timer_node));

    if (new_node == NULL) {
        printf("RTimer: malloc memory error by fkb \n");
        exit(-1);
    }
    new_node->fd        = -101;
    new_node->callback  = handler;
    new_node->callback_stream = handler_stream;
    new_node->user_data = user_data;
    new_node->interval  = interval;
    //interval_num        = interval;
    new_node->type      = type; 
    // set initial expiration
    new_value.it_value.tv_sec  = new_node->interval / 1000;// unit microSecond
    new_value.it_value.tv_nsec = (new_node->interval % 1000) * 1000000;
    // set interval for periodic timers
    if (new_node->type == TIMER_PERIODIC)
    {
        new_value.it_interval.tv_sec = new_node->interval / 1000;// unit microSecond
        new_value.it_interval.tv_nsec = (new_node->interval % 1000) * 1000000;
    }
    else if (new_node->type == TIMER_ONE_SHOT)
    {
        new_value.it_interval.tv_sec = 0;
        new_value.it_interval.tv_nsec = 0;
    }
}

RTimer::~RTimer(){
    free(new_node);
}

RTimer& RTimer::attachInterrupt(timer_handler handler) {
    new_node->callback  = handler;
    return *this;
}

RTimer& RTimer::attachInterrupt_stream(timer_handler_stream handler, void* user_data) {
    new_node->callback_stream  = handler;
    new_node->user_data = user_data;
    return *this;
}

RTimer& RTimer::detachInterrupt() {
    new_node->callback  = NULL;
    return *this;
}

RTimer& RTimer::detachInterrupt_stream() {
    new_node->callback_stream  = NULL;
    new_node->user_data = NULL;
    return *this;
}

RTimer& RTimer::setPeriod(unsigned int interval, int type){
    new_node->interval  = interval;
    interval_num        = interval;
    new_node->type      = type; 
    // set initial expiration
    new_value.it_value.tv_sec  = new_node->interval / 1000;// unit millisecond
    new_value.it_value.tv_nsec = (new_node->interval % 1000) * 1000000;
    // set interval for periodic timers
    if (new_node->type == TIMER_PERIODIC)
    {
        new_value.it_interval.tv_sec = new_node->interval / 1000;// unit millisecond
        new_value.it_interval.tv_nsec = (new_node->interval % 1000) * 1000000;
    }
    else if (new_node->type == TIMER_ONE_SHOT)
    {
        new_value.it_interval.tv_sec = 0;
        new_value.it_interval.tv_nsec = 0;
    }
    else {
        printf("Timer type is not defined, check the error\n");
        exit(-1);
    }

    if (start_flag) {
        // restart the reconfigured the timer
        timerfd_settime(new_node->fd, 0, &new_value, NULL);   
    }
    return *this;
}


RTimer& RTimer::setPeriod_us(unsigned int interval, int type){
    new_node->interval  = interval;
    interval_num        = interval;
    new_node->type      = type; 
    // set initial expiration
    new_value.it_value.tv_sec  = new_node->interval / 1000000;// unit microSecond
    new_value.it_value.tv_nsec = (new_node->interval % 1000000) * 1000;
    // set interval for periodic timers
    if (new_node->type == TIMER_PERIODIC)
    {
        new_value.it_interval.tv_sec = new_node->interval / 1000000;// unit microSecond
        new_value.it_interval.tv_nsec = (new_node->interval % 1000000) * 1000;
    }
    else if (new_node->type == TIMER_ONE_SHOT)
    {
        new_value.it_interval.tv_sec = 0;
        new_value.it_interval.tv_nsec = 0;
    }
    else {
        printf("Timer type is not defined, check the error\n");
        exit(-1);
    }

    if (start_flag) {
        // restart the reconfigured the timer
        timerfd_settime(new_node->fd, 0, &new_value, NULL);   
    }
    return *this;
}

RTimer& RTimer::setFrequency(unsigned int frep, int type){
    unsigned int temp = 1000 / frep;
    new_node->interval  = temp;
    interval_num        = temp;
    new_node->type      = type; 
    // set initial expiration
    new_value.it_value.tv_sec  = new_node->interval / 1000;// unit microSecond
    new_value.it_value.tv_nsec = (new_node->interval % 1000) * 1000000;
    // set interval for periodic timers
    if (new_node->type == TIMER_PERIODIC)
    {
        new_value.it_interval.tv_sec = new_node->interval / 1000;// unit microSecond
        new_value.it_interval.tv_nsec = (new_node->interval % 1000) * 1000000;
    }
    else if (new_node->type == TIMER_ONE_SHOT)
    {
        new_value.it_interval.tv_sec = 0;
        new_value.it_interval.tv_nsec = 0;
    }
    else {
        printf("Timer type is not defined, check the error\n");
        exit(-1);
    }

    if (start_flag) {
        // restart the reconfigured the timer
        timerfd_settime(new_node->fd, 0, &new_value, NULL);   
    }
    return *this;
}

/*RTimer& RTimer::setOneShot() {
    new_node->type = TIMER_ONE_SHOT;
    new_value.it_interval.tv_sec = 0;
    new_value.it_interval.tv_nsec = 0;
    if (start_flag) {
    timerfd_settime(new_node->fd, 0, &new_value, NULL);   
    }
    return *this;
}

RTimer& RTimer::setPeriodic() {
    new_node->type = TIMER_PERIODIC;
    new_value.it_interval.tv_sec = interval_num / 1000;// unit microSecond
    new_value.it_interval.tv_nsec = (interval_num % 1000) * 1000000;
    if (start_flag) {
    timerfd_settime(new_node->fd, 0, &new_value, NULL);   
    }
    return *this;
}
*/

bool RTimer::start(){

    new_node->fd = timerfd_create(CLOCK_REALTIME, 0);

    if (new_node->fd == -1)
    {
        printf("RTimer: creat timer error by fkb \n");
        return 0;
    }
   
    timerfd_settime(new_node->fd, 0, &new_value, NULL);

    /*Inserting the timer node into the list*/
    new_node->next = g_head;
    g_head = new_node;
    start_flag = 1;
    //return (size_t)new_node;
    return 1;
}

bool RTimer::stop(){
    start_flag = 0;
    if (new_node == NULL)
        return 1;
    struct timer_node * tmp = NULL;
    close(new_node->fd);

    if (new_node == g_head)
    {
        g_head = g_head->next;
    }

    tmp = g_head;

    while(tmp && tmp->next != new_node) tmp = tmp->next;

    if(tmp && tmp->next)
    {
        tmp->next = tmp->next->next;
    }
    return 1;  
}

void timer_finalize(){
    struct timer_node* tmp = NULL;
    if(g_head == NULL) {
        printf("remove all timers \n");
    }
    while(g_head) {
        tmp = g_head;
        g_head = g_head->next;
        free(tmp);
    }
    pthread_cancel(tid_timer);
    return;
}


struct timer_node * _get_timer_from_fd(int fd)
{
    struct timer_node * tmp = g_head;
    
    while(tmp)
    {
        if(tmp->fd == fd) return tmp;

        tmp = tmp->next;
    }
    return NULL;
}

void * _timer_thread(void * data)
{
    pthread_detach(pthread_self());
    struct pollfd ufds[MAX_TIMER_COUNT] = {{0}};
    int iMaxCount = 0;
    struct timer_node * tmp = NULL;
    int read_fds = 0, i, s;
    uint64_t exp;

    while(1)
    {
        //printf("test timers pthread \n");
        pthread_setcancelstate(PTHREAD_CANCEL_ENABLE, NULL);
        pthread_testcancel();
        pthread_setcancelstate(PTHREAD_CANCEL_DISABLE, NULL);

        iMaxCount = 0;
        tmp = g_head;

        while(tmp)
        {
            memset(&ufds[iMaxCount], 0, sizeof(struct pollfd));
            ufds[iMaxCount].fd = tmp->fd;
            ufds[iMaxCount].events = POLLIN;
            iMaxCount++;

            tmp = tmp->next;
        }
        read_fds = poll(ufds, iMaxCount, 100);

        if (read_fds <= 0) continue;

        for (i = 0; i < iMaxCount; i++)
        {
            if (ufds[i].revents & POLLIN)
            {
                s = read(ufds[i].fd, &exp, sizeof(uint64_t));

                if (s != sizeof(uint64_t)) continue;

                tmp = _get_timer_from_fd(ufds[i].fd);

                //if(tmp && tmp->callback) tmp->callback((size_t)tmp, tmp->user_data);
                if(tmp && tmp->callback) tmp->callback();
                if(tmp && tmp->callback_stream) tmp->callback_stream(tmp->user_data);

            }
        }
    }

    return NULL;
}

//#ifdef B_TIMER
RTimer TL_Timer;
//#endif

//#ifdef B_TIMER1
RTimer TL_Timer1;
//#endif

//#ifdef B_TIMER2
RTimer TL_Timer2;
//#endif

//#ifdef B_TIMER3
RTimer TL_Timer3;
//#endif

//#ifdef B_TIMER4
RTimer TL_Timer4;
//#endif

//#ifdef B_TIMER5
RTimer TL_Timer5;
//#endif

//#ifdef B_TIMER6
RTimer TL_Timer6;
//#endif

//#ifdef B_TIMER7
RTimer TL_Timer7;
//#endif
