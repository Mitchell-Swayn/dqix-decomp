#include <globaldefs.h>
ARM
extern "C" unsigned _Z22NextRandomFloatBetweenP6Randomff(void*, unsigned, unsigned);
extern "C" unsigned _fflt(unsigned);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(unsigned);
// Original: arm9/ov024 @ 0x021D8F18; symbol: func_ov024_021d8f18; size: 0x34.
extern "C" int Resource_ScaleIntegerByRandomFactor(void** random, unsigned unused1, unsigned unused2, unsigned unused3, unsigned unused4, int value) {
    unsigned randomValue = _Z22NextRandomFloatBetweenP6Randomff(*random, 0x3dcccccd, 0x3f000000);
    return _ffix(_fmul(_fflt((unsigned)value), randomValue));
}
