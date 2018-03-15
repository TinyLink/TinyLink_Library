#ifndef SENSOR_TEMPLATE_H
#define SENSOR_TEMPLATE_H

template <typename T>
class Sensor  {
private:
	int status;
protected:
	virtual int _read() = 0;
	T _data;
public:
	Sensor(T val): status(-1), _data(val) {
	}
	virtual ~Sensor() {
	}
	T data() {
		return _data;
	}
	int read() {
		status = _read();
		return status;
	}
};

#endif
