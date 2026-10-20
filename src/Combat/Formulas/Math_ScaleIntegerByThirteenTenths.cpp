#include <globaldefs.h>
ARM
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D8FD4; symbol: Math_ScaleIntegerByThirteenTenths; size: 0x24.
// Converts the sixth argument to float, multiplies by 1.3, and converts it back to integer.
extern "C" int Math_ScaleIntegerByThirteenTenths(unsigned int, unsigned int, unsigned int, unsigned int, unsigned int unused, int value) {
    return _ffix(_fmul(0x3fa66666, _fflt(value)));
}
