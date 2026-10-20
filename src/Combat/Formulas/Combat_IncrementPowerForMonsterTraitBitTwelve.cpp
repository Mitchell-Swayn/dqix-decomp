#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void *, int, int, int);
// Original: arm9/ov024 @ 0x021D8A84; symbol: func_ov024_021d8a84; size: 0x30.
extern "C" int Combat_IncrementPowerForMonsterTraitBitTwelve(void **object, int unused, int index, int unused2, int unused3, int base) {
    if (Combat_TestMonsterDescriptorMode(*object, (short)index, 0, 1))
        return base + 1;
    return base;
}
