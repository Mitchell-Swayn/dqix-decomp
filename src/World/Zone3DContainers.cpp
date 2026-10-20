#include "World/Zone3D.h"
#include "World/LootableContainer.h"

extern "C"
{
    void ZoneContainerRenderPart_ShareFrameAndAnimationResources(void*, ZoneContainerRenderPart*);
}

// Original: arm9/main @ 0x02013B70; symbol: _ZN6Zone3D28CreateContainerRenderEntriesEP13SafeAllocator; size: 0x140.
void Zone3D::CreateContainerRenderEntries(SafeAllocator* allocator)
{
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    LootableContainerManager::Container* container;
    ZoneContainerRenderEntry* entry;
    int i;
    unsigned short color = LightingManager::GetInstance()->maybePotBarrelDiffuseColor_;
    container = manager->pContainerList_;
    int count = 0;
    for (; container; container = container->pNext)
        if (container->containerType == 1 || container->containerType == 2)
            ++count;
    unknown_478_ = (ZoneContainerRenderEntry*)allocator->Allocate(count * sizeof(ZoneContainerRenderEntry));
    if (!unknown_478_) return;
    for (container = manager->pContainerList_; container; container = container->pNext)
    {
        if (container->containerType == 1 || container->containerType == 2)
        {
            entry = &unknown_478_[unknown_476_];
            ResetZoneContainer(entry);
            entry->mainPart.Reset();
            entry->mainPart.diffuseColor = color;
            entry->brokenPart.Reset();
            entry->brokenPart.diffuseColor = color;
            for (i = 0; i < 4; ++i)
            {
                entry->fragments[i].Reset();
                entry->fragments[i].diffuseColor = color;
            }
            entry->mainPart.position = container->position;
            entry->mainPart.scale.x = 0x80;
            entry->mainPart.scale.y = 0x80;
            entry->mainPart.scale.z = 0x80;
            entry->containerID = container->uniqueID;
            entry->state = 0;
            ++unknown_476_;
        }
    }
    BindContainerModels();
}

struct ZoneContainerSavedState
{
    unsigned short zoneID;
    unsigned short flags;
};
extern "C" void* ZoneState_GetTrackedZoneCache();
extern "C" ZoneContainerSavedState* ZoneState_FindTrackedZoneByIdentifier(void*, unsigned short);

// Original: arm9/main @ 0x02013CB0; symbol: _ZN6Zone3D22SetContainerBrokenMaskEj; size: 0x74.
void Zone3D::SetContainerBrokenMask(unsigned int mask)
{
    for (int i = 0; i < unknown_476_; ++i)
        if (mask & (1 << i))
            unknown_478_[i].state = -1;
    ZoneContainerSavedState* state = ZoneState_FindTrackedZoneByIdentifier(ZoneState_GetTrackedZoneCache(), currentZoneID_);
    // Persist the twelve container bits while retaining the low four flags.
    if (state)
        state->flags = (state->flags & 0xffff000f) | ((mask << 20) >> 16);
}

// Original: arm9/main @ 0x02013D24; symbol: _ZN6Zone3D19BindContainerModelsEv; size: 0xF4.
void Zone3D::BindContainerModels()
{
    LootableContainerManager* manager = LootableContainerManager::GetMainInstance();
    for (int i = 0; i < unknown_476_; ++i)
    {
        ZoneContainerRenderEntry* entry = &unknown_478_[i];
        LootableContainerManager::Container* container = manager->GetContainerByID(entry->containerID, NULL);
        if (!container) continue;
        if (container->containerType == 1)
        {
            ZoneContainerRenderPart_ShareFrameAndAnimationResources(containerModels_[0], &entry->mainPart);
            ZoneContainerRenderPart_ShareFrameAndAnimationResources(containerModels_[1], &entry->brokenPart);
            for (int j = 0; j < 4; ++j)
                ZoneContainerRenderPart_ShareFrameAndAnimationResources(containerModels_[2], &entry->fragments[j]);
        }
        else if (container->containerType == 2)
        {
            ZoneContainerRenderPart_ShareFrameAndAnimationResources(containerModels_[3], &entry->mainPart);
            ZoneContainerRenderPart_ShareFrameAndAnimationResources(containerModels_[4], &entry->brokenPart);
            for (int j = 0; j < 4; ++j)
                ZoneContainerRenderPart_ShareFrameAndAnimationResources(containerModels_[5], &entry->fragments[j]);
        }
    }
}
