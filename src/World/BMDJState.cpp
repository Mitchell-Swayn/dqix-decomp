#include "World/BMDJ.h"

extern "C" void* GameState_GetSerializedProgressState();

// The middle argument is unused; flag 4's gameplay role is still uncertain.
// Original: arm9/main @ 0x02013380; symbol: _Z15UpdateBMDJFlag4PN17Zone3D_BMDJStruct13InstanceEntryEii; size: 0x34.
void UpdateBMDJFlag4(Zone3D_BMDJStruct::InstanceEntry* instance, int unused, int clear)
{
    GameState_GetSerializedProgressState();
    if (clear) instance->flags &= ~4;
    else instance->flags |= 4;
    instance->flags |= 0x40;
}
// Meaning of this high bit remains unresolved; the low seven bits are a countdown.
// Original: arm9/main @ 0x020133B4; symbol: _Z22SetBMDJUnknownHighFlagPN17Zone3D_BMDJStruct13InstanceEntryEb; size: 0x18.
void SetBMDJUnknownHighFlag(Zone3D_BMDJStruct::InstanceEntry* instance, bool value)
{
    if (value)
        instance->unknown_4_high = -1;
    else
        instance->unknown_4_high = 0;
}
