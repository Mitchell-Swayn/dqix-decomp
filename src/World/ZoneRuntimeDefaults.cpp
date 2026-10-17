#include "World/Zone3DContainers.h"
#include "Grotto/Main/TileFeatures.h"
#include "std_library_functions.h"


// Original: arm9/main @ 0x02012FA4; symbol: _Z22ResetZoneFragmentPartsP23ZoneContainerRenderPart; size: 0x40.
void ResetZoneFragmentParts(ZoneContainerRenderPart* parts)
{
    for (signed char i = 0; i < 4; ++i)
    {
        parts[i].ResetIfFlag0();
        parts[i].Reset();
    }
}
