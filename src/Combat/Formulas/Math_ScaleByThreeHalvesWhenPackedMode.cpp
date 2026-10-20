#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void*, int, int, int);
extern "C" int _fflt(int);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(unsigned);
// Original: arm9/ov024 @ 0x021D9084; symbol: func_ov024_021d9084; size: 0x44.
extern "C" int Math_ScaleByThreeHalvesWhenPackedMode(void** object, int ignored1, int index, int ignored2, int ignored3, int value) {
    if (!Combat_TestMonsterDescriptorMode(*object, (short)index, 0, 0)) return value;
    return _ffix(_fmul(0x3fc00000, (unsigned)_fflt(value)));
}
