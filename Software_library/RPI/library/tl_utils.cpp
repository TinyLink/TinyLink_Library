#include "tl_utils.h"

namespace tinylink {
    int NumberUtils::num_digits(long val) {
        int cnt = 0;
        if (val < 0) {
            ++cnt;
            val = -val;
        }
        while (val) {
            ++cnt;
            val /= 10;
        }
        return cnt;
    }
    int NumberUtils::num_digits(double val, int precision) {
        int cnt = 0; 
        if (val < 0) {
            ++cnt;
            val = -val;
        }   

        const int bit = 8 * sizeof(long) - 1;
        while (val > ((1L << bit) - 1)) {
            ++cnt;
            val /= 10.0;
        }
        return (cnt + num_digits((long)val) + ((precision == 0)? 0: (1 + precision)));
    }
}
