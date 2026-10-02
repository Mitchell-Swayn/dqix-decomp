#include "World/Zone3D.h"

extern "C" void func_020de848(void*);

void Zone3D::ResetZoneResources(bool destroyAllocators)
{
    textureImageMemory_ = 0;
    texturePaletteMemory_ = 0;
    unknown_424_ = 0;
    firstBMDJStruct_41c_ = NULL;
    firstModel_418_ = NULL;
    unknown_476_ = 0;
    numChests_ = 0;
    unknown_82c_ = 0;
    unknown_474_ = 0;
    unknown_82c_ = 0;
    unknown_42c_ = 0;
    mapListLoadHandle_ = -1;
    unknown_434_ = -1;
    mapAMBLLoadHandle_ = -1;
    mapAMDJLoadHandle_ = -1;
    atsAMBLLoadHandle_ = -1;
    unknown_478_ = NULL;
    unknown_47c_ = NULL;
    unk_23bc[0] = 0;
    unk_23bc[1] = 0;
    unknown_834_ = 0;
    bFeatures_.Reset();
    func_020de848(unknown_struct_2754_);
    atmosphericEffects_.Reset();
    ResetZoneFragmentParts(fragmentParts_);
    if (destroyAllocators)
    {
        if (transitionAllocator_.GetSignedAllocator())
        {
            transitionAllocator_.Destroy();
            transitionAllocator_.ResetAllocatorPointer();
        }
        if (internalAllocator_.GetSignedAllocator())
        {
            internalAllocator_.Destroy();
            internalAllocator_.ResetAllocatorPointer();
        }
    }
}
