#include <globaldefs.h>
extern "C" int rand();
extern "C" double _dflt(int);
extern "C" double _ddiv(double, double);
extern "C" double _dmul(double, double);
extern "C" int _dfix();
// Original: arm9/main @ 0x020323C4; symbol: func_020323c4; size: 0x60.
extern "C" int Random_SelectScaledInclusiveIntegerRange(int low, int high) {
    int r = rand();
    double width = _dflt((high + 1) - low);
    double numerator = _dflt(r - 1);
    double fraction = _ddiv(numerator, 32767.0);
    double product = _dmul(width, fraction);
    int scaled = _dfix();
    return low + scaled;
}
