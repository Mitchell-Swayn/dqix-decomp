#include <globaldefs.h>
ARM
extern "C" int TestIndexedObjectPackedMode(void *, int, int, int);
extern "C" int ConvertIntToFloatBits(int);
extern "C" unsigned int MultiplyFloatBits(unsigned int, unsigned int);
extern "C" int ConvertFloatBitsToInt(unsigned int);
// Original: arm9/ov024 @ 0x021D8F90; symbol: func_ov024_021d8f90; size: 0x44.
extern "C" int AdjustValueByPackedMode(void **object, int unused, int index, int unused2, int unused3, int value) {
    if (!TestIndexedObjectPackedMode(*object, (short)index, 5, 0)) return value;
    return (int)((float)value * 1.5f);
}
