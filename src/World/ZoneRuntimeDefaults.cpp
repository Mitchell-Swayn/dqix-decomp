#include "World/Zone3DContainers.h"
#include "Grotto/Main/TileFeatures.h"
#include "std_library_functions.h"


void ResetZoneFragmentParts(ZoneContainerRenderPart* parts)
{
    for (signed char i = 0; i < 4; ++i)
    {
        parts[i].ResetIfFlag0();
        parts[i].Reset();
    }
}
