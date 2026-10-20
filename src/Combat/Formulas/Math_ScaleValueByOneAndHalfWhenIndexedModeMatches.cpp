#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void *, int, int, int);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
// Original: arm9/ov024 @ 0x021D91C0; symbol: func_ov024_021d91c0; size: 0x44.
extern "C" int Math_ScaleValueByOneAndHalfWhenIndexedModeMatches(void *self, int unused1, int index, int unused3, int unused4, int value) {
    if (!Combat_TestMonsterDescriptorMode(*(void **)self, (short)index, 10, 0)) return value;
    return _ffix(_fmul(0x3FC00000, (unsigned int)_fflt(value)));
}
