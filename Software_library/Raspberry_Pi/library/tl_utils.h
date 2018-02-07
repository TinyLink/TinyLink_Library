#ifndef TINYLINK_UTILS
#define TINYLINK_UTILS

namespace tinylink {
	class NumberUtils {
	public:
	    static int num_digits(long val);
	    static int num_digits(double val, int precision = 2);
	};
}

#endif
