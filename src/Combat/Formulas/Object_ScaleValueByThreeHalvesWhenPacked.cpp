#include <globaldefs.h>
ARM
extern "C" int Combat_TestMonsterDescriptorMode(void*, int, int, int);
// Original: arm9/ov024 @ 0x021D8F4C; symbol: func_ov024_021d8f4c; size: 0x44.
extern "C" int Object_ScaleValueByThreeHalvesWhenPacked(void** object, unsigned unused, int index, unsigned unused2, unsigned unused3, int value) {
    if (Combat_TestMonsterDescriptorMode(*object, (short)index, 0xc, 0) == 0) return value;
    return (int)((float)value * 1.5f);
}
