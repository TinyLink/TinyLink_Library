#ifndef READ_STREAM_H
#define READ_STREAM_H
#if 0
#include <pthread.h>
#include "bbb_timer.h"

typedef void (*Handler) (void* arg);

template<typename T>
class ReadStream {
private:
// timer for read
	BTimer read_timer;
// Point to the address of the buffer array
	T* buffer;
// The count set by user
	int count;
// The real count of data_stream read
	int real_count;
// the max count that can be filler by buffer posted by user 
	int buffer_count;
	Handler process;
// for others sampleing period in microseconds
	int period;
//-------------------------------------------
	pthread_mutex_t mutex;

protected:
	T data_stream;
// Read one stream data from specified memory. when reading successfully, return ture; when reading unsuccessfully
// return false
	virtual int readOnce() = 0;

// Excuted when the timer expires
	static void callback(void* arg) {
		ReadStream* temp = (ReadStream*)arg;
		static int cnt = 0;
		static int real_cnt = 0;
		if (cnt < temp->count) {
			cnt++;
			// whether to check read_once succeed
			if(temp->readOnce()) {
				*temp->buffer = temp->data_stream;
				temp->buffer++;
				real_cnt++;	
			}
/*			else {
				read_timer.stop();
				// lock prevent the competition
				pthread_mutex_lock(&mutex);
				count = cnt;
				pthread_mutex_unlock(&mutex);
				process();
				return;			
			}*/
		} 
		else {
			temp->read_timer.stop();
			pthread_mutex_lock(&temp->mutex);
			temp->real_count = real_cnt;
			pthread_mutex_unlock(&temp->mutex);
			
			temp->process(NULL);
			cnt = 0;
			real_cnt = 0;
		}
	}

public:

	ReadStream(T val):buffer(NULL), count(0), real_count(0), buffer_count(0), process(NULL), period(0), data_stream(val) {
		pthread_mutex_init(&mutex, NULL);
	}
	virtual ~ReadStream() {
		pthread_mutex_destroy(&mutex);
	}

// Set the callback function excuted when the reading opeartion completes / is  broken
	void setReadProces(Handler process1) {
		process = process1;
	}

// Pass a buffer to the device, and indicates the most values can be placed into the buffer. Para size is the actual number of elements in buffer
// How to implement post more than one buffers???
	void postBuffer(T* buffer, int size) {
		this->buffer = &buffer;
		buffer_count = size;
	}

// Return the number of stream data available, less than or equal to the parm. count in readStream()/ setSampleNumber()
// if the return number is less than count in readStream(), the last read operatuion fails
	int available() {
		int temp;
		pthread_mutex_lock(&mutex);
		temp = real_count;
		pthread_mutex_unlock(&mutex);
		return temp;
	}
//----------------------------------------my--------------------------------------------

// Direct the device to start filling the buffer by sampling with the specified period and the number of sampling data
// Make ture para count is less than or equal to the para size of postBuffer()
	void readStream(int usPeriod,  int count) {
		buffer_count > count? this->count = count : this->count = buffer_count;
		read_timer.setPeriod_us(usPeriod, 1);
		read_timer.attachInterrupt_stream(callback, this);
		read_timer.start();
	}

//----------------------------------------my--------------------------------------------

//---------------------------------------others----------------------------------
// Set sampling period in microseconds
	void setSamplePeriod(int usPeriod) {
		read_timer.setPeriod_us(usPeriod, 1);
		period = usPeriod;
	}

// Set sampling frequency
	void setSampleFreq(int frep) {
		read_timer.setPeriod_us(1000000/frep, 1);
		period = 1000000/frep;
	}

// Set total sampling time in microseconds
	void setSampleTime(int interval) {
		buffer_count > interval/period? this->count = interval/period : this->count = buffer_count;
		
	}

// Set total sampling number 
	void setSampleNumber(int count) {
		buffer_count > count? this->count = count : this->count = buffer_count;
	}

// Start sampling data
	void readStart() {
		read_timer.attachInterrupt(callback);
		read_timer.start();
	}
//---------------------------------------others----------------------------------

};

#endif
#endif
