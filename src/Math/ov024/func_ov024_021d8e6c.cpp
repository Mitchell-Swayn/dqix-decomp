#include <globaldefs.h>
ARM
extern "C" int TestIndexedObjectPackedMode(void *, int, int, int);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D8E6C; symbol: func_ov024_021d8e6c; size: 0x44.
extern "C" int func_ov024_021d8e6c(void **base, int unused, int index, int unused2, int unused3, int value) {
    if (!TestIndexedObjectPackedMode(*base, (short)index, 8, 0)) return value;
    int floatBits = _fflt(value);
    floatBits = _fmul(0x3fc00000, floatBits);
    return _ffix((unsigned int)floatBits);
}
