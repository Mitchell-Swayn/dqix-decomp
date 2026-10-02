#include "World/WorldPlacementSource.h"
#include "Resource/GameResources.h"
#include "std_library_functions.h"

void WorldPlacementSource::Reset()
{
    memset(unknown0, 0, sizeof(unknown0));
    memset(unknown10, 0, sizeof(unknown10));
    head = 0;
    count = 0;
    unknownA = 0;
    unknownC = 0;
}

void WorldPlacementSource::ClearPlacements()
{
    func_ov017_0218b5b0()->allocator_array_1a0[0].Reset();
    head = 0;
    count = 0;
    unknownC = 0;
}
