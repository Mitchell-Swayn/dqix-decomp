#include "World/WorldPlacementSource.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

void WorldPlacementSource::Reset()
{
    memset(mapPrefix, 0, sizeof(mapPrefix));
    memset(variants, 0, sizeof(variants));
    head = 0;
    count = 0;
    unknownA = 0;
    randomValues = 0;
}

void WorldPlacementSource::ClearPlacements()
{
    func_ov017_0218b5b0()->allocator_array_1a0[0].Reset();
    head = 0;
    count = 0;
    randomValues = 0;
}
