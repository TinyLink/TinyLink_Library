/* Implement GPIO using files.
 * This needs the user be root or in group gpio.
 */

/*
 * I do not dare to use anything related to string.
 * So let's hope sprintf will work.
 * */

#include "OUTLED_LED_RPI.h"
#include <cassert>
#include "TL_Config.h"

namespace tinylink {
    void LedFile::_openPin(int pin) {
        _closePin();

        _pin = pin;
        FILE *fp = fopen("/sys/class/gpio/export", "w");
        if (fp) fprintf(fp, "%d", _pin);
        fclose(fp);
    }
    void LedFile::_closePin() {
        if (_pin < 0) return;

        if (_direction) fclose(_direction);
        if (_value) fclose(_value);

        FILE *fp = fopen("/sys/class/gpio/unexport", "w");
        if (fp) fprintf(fp, "%d", _pin);
        fclose(fp);
    }

    LedFile &LedFile::setPin(int pin) {
        _openPin(pin);
        sprintf(_direction_path, "/sys/class/gpio/gpio%d/direction", _pin);
        _direction = fopen(_direction_path, "w");
        sprintf(_value_path, "/sys/class/gpio/gpio%d/value", _pin);
        _value = fopen(_value_path, "w");

        _set_direction(1); //better try

        return *this;
    }
    LedFile::~LedFile() {
        _closePin();
    }

    void LedFile::_set_direction(int direction) {
        char dir[][4] = {"in", "out"};
        fprintf(_direction, "%s", dir[direction]);
        fflush(_direction);
        _mode = direction;
    }

    void LedFile::_digitalWrite(int value) {
        if (_mode != 1) _set_direction(1);
        fprintf(_value, "%d", value);
        //fflush(_value);
    }
    int LedFile::_digitalRead() {
        assert(_pin >= 0);
        if (_mode != 0) _set_direction(0);
        int ans;
        fscanf(_value, "%d", &ans);
        return ans;
    }
    void LedFile::turnOn(void) {
        _digitalWrite(1);
    }
    void LedFile::turnOff(void) {
        _digitalWrite(0);
    }
    void LedFile::toggle(void) {
        _digitalWrite((_digitalRead() == 1)? 0: 1);
    }
    int LedFile::state(void) {
        return _digitalRead();
    }
}

tinylink::LedFile TL_LED(LED_DIGITAL_OUTPUT);
