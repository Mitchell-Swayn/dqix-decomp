#include "World/WorldPlacementSource.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

// Original: arm9/main @ 0x0208E4BC; symbol: _ZN20WorldPlacementSource5ResetEv; size: 0x3C.
void WorldPlacementSource::Reset()
{
    memset(mapPrefix, 0, sizeof(mapPrefix));
    memset(variants, 0, sizeof(variants));
    head = 0;
    count = 0;
    unknownA = 0;
    randomValues = 0;
}

// Original: arm9/main @ 0x0208E4F8; symbol: _ZN20WorldPlacementSource15ClearPlacementsEv; size: 0x28.
void WorldPlacementSource::ClearPlacements()
{
    GameResources_GetInstance()->allocator_array_1a0[0].Reset();
    head = 0;
    count = 0;
    randomValues = 0;
}
