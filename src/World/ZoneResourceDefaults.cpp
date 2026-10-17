#include "World/Zone3DContainers.h"
#include "World/BMDJ.h"


// Original: arm9/main @ 0x020133CC; symbol: _Z18ResetZoneContainerP24ZoneContainerRenderEntry; size: 0x30.
void ResetZoneContainer(ZoneContainerRenderEntry* entry)
{
    entry->containerID = 0;
    entry->state = -1;
    entry->unknown_4 = 0;
    entry->mainPart.Reset();
    entry->brokenPart.Reset();
}

// Original: arm9/main @ 0x020133FC; symbol: _Z14ResetZoneChestP14ZoneChestEntry; size: 0x58.
void ResetZoneChest(ZoneChestEntry* chest)
{
    SetVector3iComponents(&chest->position, 0, 0, 0);
    chest->unknown_c = 0;
    chest->lidAngle = 0;
    chest->timer = 0;
    chest->state = 1;
    chest->unknown_17 = 0;
    chest->unknown_1a = -1;
    chest->unknown_1c = 0;
    chest->ownerIndex = -1;
    chest->unknown_20 = 0;
    chest->unknown_19 = 0;
    chest->loadHandle = -1;
    chest->unknown_18 = 0;
}

// Original: arm9/main @ 0x02013454; symbol: _Z14ResetBMDJGroupP17Zone3D_BMDJStruct; size: 0x3C.
void ResetBMDJGroup(Zone3D_BMDJStruct* group)
{
    group->unknown_0_ = -1;
    group->ptr_40 = NULL;
    group->ptr_44 = NULL;
    group->pNext_ = NULL;
    group->scriptData_.Reset();
    group->vec_48_.x = 0;
    group->vec_48_.y = 0;
    group->vec_48_.z = 0;
}
