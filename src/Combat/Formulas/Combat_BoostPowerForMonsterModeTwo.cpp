#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void*, int, int, int);
extern "C" int _fflt(int);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(void);
// Original: arm9/ov024 @ 0x021D8A40; symbol: func_ov024_021d8a40; size: 0x44.
extern "C" int Combat_BoostPowerForMonsterModeTwo(void** object, int unused, int index, int unused2, int unused3, int value) {
    if (!Combat_TestMonsterDescriptorMode(*object, (short)index, 2, 0)) return value;
    unsigned int f = (unsigned int)_fflt(value);
    f = _fmul(0x3fc00000, f);
    return _ffix();
}
