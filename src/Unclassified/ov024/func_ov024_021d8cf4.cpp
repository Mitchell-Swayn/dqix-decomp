#include <globaldefs.h>
ARM
extern "C" int TestIndexedObjectPackedMode(void *, int, int, int);
extern "C" unsigned int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D8CF4; symbol: func_ov024_021d8cf4; size: 0x44.
extern "C" int func_ov024_021d8cf4(void **object, int unused1, int index, int unused2, int unused3, int amount) {
    if (!TestIndexedObjectPackedMode(*object, (short)index, 3, 0)) return amount;
    return _ffix(_fmul(0x3fc00000, _fflt(amount)));
}
