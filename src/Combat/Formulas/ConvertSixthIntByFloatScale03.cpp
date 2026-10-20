#include <globaldefs.h>
ARM
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D8EB0; symbol: func_ov024_021d8eb0; size: 0x24.
extern "C" int ConvertSixthIntByFloatScale03(int a0, int a1, int a2, int a3, int a4, int value) {
    unsigned int valueFloat = _fflt(value);
    return _ffix(_fmul(0x3e99999a, valueFloat));
}
