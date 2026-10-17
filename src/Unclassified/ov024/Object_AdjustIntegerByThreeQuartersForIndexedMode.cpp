#include <globaldefs.h>
ARM
extern "C" int TestIndexedObjectPackedMode(void *, int, int, int);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(int);
// Original: arm9/ov024 @ 0x021D9174; symbol: func_ov024_021d9174; size: 0x44.
extern "C" int Object_AdjustIntegerByThreeQuartersForIndexedMode(void **object, unsigned int arg1, int index, unsigned int arg3, unsigned int arg4, int value) {
    if (TestIndexedObjectPackedMode(*object, (short)index, 4, 0) == 0) {
        return value;
    }
    int floatValue = _fflt(value);
    unsigned int product = _fmul(0x3FC00000, (unsigned int)floatValue);
    return _ffix((int)product);
}
