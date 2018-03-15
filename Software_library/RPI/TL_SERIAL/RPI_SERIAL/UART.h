#ifndef UART_H
#define UART_H

#include <string>
#include "WString.h"
using std::string;

namespace tinylink {
	class Serial {
	private:
		int _fd = -1;
		string _dev = string("/dev/ttyAMA0");	

	public:
		void begin(unsigned long speed);
		void end(void);
		int available(void);
		int print(int val);
		int print(long val);
		int print(double val);
		int print(const char *str);
		int println(int val);
		int println(long val);
		int println(double val);
		int println(const char *str);
		int read(void);
		void flush(void);
	// Done by fkb
		int print(const String& str);
		int println(const String& str);

	//TODO:should we provide these functions?
		Serial &setDevice(string dev);
		Serial &setDevice(const char *dev);
	};
}

extern tinylink::Serial TL_Serial;

#endif
