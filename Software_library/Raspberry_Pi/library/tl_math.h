#ifndef TINYLINK_MATH
#define TINYLINK_MATH

#include <cmath>

namespace tinylink{
class Math {
public:
    double sin(double rad) { return std::sin(rad); }
    double cos(double rad) { return std::cos(rad); }
    double tan(double rad) { return std::tan(rad); }
    double abs(double rad) { return std::abs(rad); }
    double pow(double base, double exp) { return std::pow(base, exp); }
    double sqrt(double rad) { return std::sqrt(rad); }
    template <class T>
    const T &min(const T &a, const T &b) { return ((a > b)? b: a); }
    template <class T>
    const T &max(const T &a, const T &b) { return ((a > b)? a: b); }
};
}

#endif
