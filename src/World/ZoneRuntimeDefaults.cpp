#include "World/Zone3DContainers.h"
#include "Grotto/Main/TileFeatures.h"
#include "std_library_functions.h"

extern "C" void func_02047230(ZoneContainerRenderPart*);
extern "C" void func_0204719c(ZoneContainerRenderPart*);

void ResetZoneFragmentParts(ZoneContainerRenderPart* parts)
{
    for (signed char i = 0; i < 4; ++i)
    {
        func_02047230(&parts[i]);
        func_0204719c(&parts[i]);
    }
}
