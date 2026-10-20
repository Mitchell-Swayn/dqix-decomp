#include <globaldefs.h>
#include <std_library_functions.h>
#include <Resource/GameResources.h>
#include <World/Zone3D.h>
#include <World/WorldObjectInstanceList.h>
#pragma force_active on
ARM
extern "C" void* Zone3D_GetMainInstance();
extern "C" void ZoneContainer_ResetFourRenderParts(char*);
extern "C" WorldObjectInstanceList* WorldObjectInstanceList_GetInstance();
extern "C" void TextureVRAM_SnapshotAllocationBounds(char*);
// Original data: arm9/ov017 @ 0x021D64B0; symbol: data_ov017_021d64b0.
extern "C" const int Field_ReleaseChestPickupAndInteractionVisuals_SentinelTerminatedIndexList[17];
// Original: arm9/ov017 @ 0x0219B938; symbol: func_ov017_0219b938; size: 0xD4.
// Releases chest models, interaction render parts and their allocator staging state.
extern "C" void Field_ReleaseChestPickupAndInteractionVisuals(void* context)
{
    GameResources* resources=(GameResources*)context;
    Zone3D* zone=(Zone3D*)Zone3D_GetMainInstance();
    zone->models_498_[0].CancelVramStagingAndClear();
    Model3D* second=zone->models_498_;
    ++second;
    second->CancelVramStagingAndClear();
    ZoneContainer_ResetFourRenderParts(*(char**)((char*)resources+0x4328));
    int indices[17];
    COPY_ARRAY(indices,Field_ReleaseChestPickupAndInteractionVisuals_SentinelTerminatedIndexList);
    for(int i=0;indices[i]>=0;++i)
        ((ZoneContainerRenderPart*)&resources->substruct_array_2b90[indices[i]])->Reset();
    ((ZoneContainerRenderPart*)resources->unknown_3520)->Reset();
    ((ZoneContainerRenderPart*)resources->unknown_35a8)->Reset();
    WorldObjectInstanceList_GetInstance()->SetObject(0);
    resources->allocator_array_38[5].Reset();
    TextureVRAM_SnapshotAllocationBounds((char*)resources+0x4fc);
}
