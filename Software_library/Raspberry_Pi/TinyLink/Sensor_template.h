#ifndef SENSOR_TEMPLATE_H
#define SENSOR_TEMPLATE_H

#include <pthread.h>

template <typename T>
class Sensor  {
private:
	pthread_mutex_t mutex;
	pthread_t thread_id;
	int status;

protected:
	virtual int _read() = 0;
	T _data;

public:

	Sensor(T val): status(-100), _data(val) {
		pthread_mutex_init(&mutex, NULL);
	}
	virtual ~Sensor() {
		pthread_mutex_destroy(&mutex);
	}
	T data() {
		T temp;
		pthread_mutex_lock(&mutex);
		temp = _data;
		pthread_mutex_unlock(&mutex);
		return temp;	
	}
	int read()  {
		return read_BL();
	}

	int read_BL() {
		pthread_mutex_lock(&mutex);
		status = _read();
		pthread_mutex_unlock(&mutex);
		return status;
	}
	void read_NBL() {
		pthread_create(&thread_id, NULL, read_thread, this);
	}
	static void *read_thread(void *arg) {
		pthread_detach(pthread_self());	
		Sensor* temp = (Sensor*) arg;
		//while(1)
		{
			temp->read_BL();
			#ifdef DEBUG
			printf("In thread ID = %lu \n", pthread_self());
			#endif
			pthread_exit(0);		
		}
	}
};

#endif