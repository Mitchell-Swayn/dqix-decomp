#include "World/BMDJ.h"

extern "C" void* func_0205ec34();

// The middle argument is unused; flag 4's gameplay role is still uncertain.
void UpdateBMDJFlag4(Zone3D_BMDJStruct::InstanceEntry* instance, int unused, int clear)
{
    func_0205ec34();
    if (clear) instance->flags &= ~4;
    else instance->flags |= 4;
    instance->flags |= 0x40;
}
// Meaning of this high bit remains unresolved; the low seven bits are a countdown.
void SetBMDJUnknownHighFlag(Zone3D_BMDJStruct::InstanceEntry* instance, bool value)
{
    if (value)
        instance->unknown_4_high = -1;
    else
        instance->unknown_4_high = 0;
}
