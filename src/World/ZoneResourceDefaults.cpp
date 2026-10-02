#include "World/Zone3DContainers.h"
#include "World/BMDJ.h"

extern "C" void func_0204719c(ZoneContainerRenderPart*);

void ResetZoneContainer(ZoneContainerRenderEntry* entry)
{
    entry->containerID = 0;
    entry->state = -1;
    entry->unknown_4 = 0;
    func_0204719c(&entry->mainPart);
    func_0204719c(&entry->brokenPart);
}

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
