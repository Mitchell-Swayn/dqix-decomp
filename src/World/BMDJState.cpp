#include "World/BMDJ.h"

// Meaning of this high bit remains unresolved; the low seven bits are a countdown.
void SetBMDJUnknownHighFlag(Zone3D_BMDJStruct::InstanceEntry* instance, bool value)
{
    if (value)
        instance->unknown_4_high = -1;
    else
        instance->unknown_4_high = 0;
}
