#include "SERIAL_RPI.h"
#include "tl_utils.h"
#include "wiringSerial.h"
#include <cassert>
#include <string>
#include <cstring>
using std::string;

namespace tinylink {

	Serial &Serial::setDevice(string dev) {
		_dev = dev;
	    return *this;
	}	

	Serial &Serial::setDevice(const char *str) {
		_dev = string(str);
	    return *this;
	}	

	//TODO: how to find the right device to use
	void Serial::begin(unsigned long speed) {
		_fd = ::serialOpen(_dev.c_str(), speed);
	}	

	void Serial::end() {
		assert (_fd >= 0);
		serialClose(_fd);
	}	

	int Serial::available(void) {
		assert (_fd >= 0);
		return serialDataAvail(_fd);
	}
	int Serial::print(int val) {
		return print((long)val);
	}
	int Serial::print(long val) {
		assert (_fd >= 0);
		serialPrintf(_fd, "%ld", val);
	    return NumberUtils::num_digits(val);
	}
	int Serial::print(double val) {
		assert (_fd >= 0);
		serialPrintf(_fd, "%.2f", val);
	    return NumberUtils::num_digits(val);
	}
	int Serial::print(const char *str) {
		assert (_fd >= 0);
		serialPrintf(_fd, "%s", str);
	    return strlen(str);
	}

	int Serial::print(const String& str) {
		print(str.c_str());
	}


	int Serial::println(int val) {
		return println((long)val);
	}
	int Serial::println(long val) {
		assert (_fd >= 0);
		serialPrintf(_fd, "%d\r\n", val);
	    return (2 + NumberUtils::num_digits(val));
	}
	int Serial::println(double val) {
		assert (_fd >= 0);
	    serialPrintf(_fd, "%f\r\n", val);
	    return (2 + NumberUtils::num_digits(val));
	}
	int Serial::println(const char *str) {
		assert (_fd >= 0);
		serialPrintf(_fd, "%s\r\n", str);
	    return (2 + strlen(str));
	}
	int Serial::println(const String& str) {
		println(str.c_str());
	}

	int Serial::read(void) {
		assert (_fd >= 0);
		return serialGetchar(_fd);
	}
	void Serial::flush(void) {
		assert (_fd >= 0);
		serialFlush(_fd);
	}

}

tinylink::Serial TL_Serial;
