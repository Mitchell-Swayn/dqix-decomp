#include "World/Zone3D.h"
#include "World/LootableContainer.h"

extern "C"
{
    void func_0204719c(ZoneContainerRenderPart*);
    void func_02048004(void*, ZoneContainerRenderPart*);
}

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
            func_0204719c(&entry->mainPart);
            entry->mainPart.diffuseColor = color;
            func_0204719c(&entry->brokenPart);
            entry->brokenPart.diffuseColor = color;
            for (i = 0; i < 4; ++i)
            {
                func_0204719c(&entry->fragments[i]);
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
extern "C" void* func_02027ca4();
extern "C" ZoneContainerSavedState* func_02028bd0(void*, unsigned short);

void Zone3D::SetContainerBrokenMask(unsigned int mask)
{
    for (int i = 0; i < unknown_476_; ++i)
        if (mask & (1 << i))
            unknown_478_[i].state = -1;
    ZoneContainerSavedState* state = func_02028bd0(func_02027ca4(), currentZoneID_);
    // Persist the twelve container bits while retaining the low four flags.
    if (state)
        state->flags = (state->flags & 0xffff000f) | ((mask << 20) >> 16);
}

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
            func_02048004(containerModels_[0], &entry->mainPart);
            func_02048004(containerModels_[1], &entry->brokenPart);
            for (int j = 0; j < 4; ++j)
                func_02048004(containerModels_[2], &entry->fragments[j]);
        }
        else if (container->containerType == 2)
        {
            func_02048004(containerModels_[3], &entry->mainPart);
            func_02048004(containerModels_[4], &entry->brokenPart);
            for (int j = 0; j < 4; ++j)
                func_02048004(containerModels_[5], &entry->fragments[j]);
        }
    }
}
