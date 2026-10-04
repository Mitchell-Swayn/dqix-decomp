#include "World/Zone3D.h"
#include "World/LootableContainer.h"

void Zone3D::ReleaseChestsForOwner(int ownerIndex)
{
    int valid = ownerIndex >= 0 && ownerIndex <= 3;
    if (!valid) return;
    for (int i = 0; i < numChests_; ++i)
    {
        ZoneChestEntry* chest = &unknown_47c_[i];
        if (chest->unknown_20 && chest->ownerIndex == ownerIndex)
        {
            chest->unknown_20 = 0;
            unknown_820_ = 0;
        }
    }
}

bool Zone3D::HasActiveChest()
{
    if (!LootableContainerManager::GetMainInstance()) return false;
    if (!pUnknownStruct_8_) return false;
    for (int i = 0; i < numChests_; ++i)
    {
        unsigned int state = unknown_47c_[i].state;
        if (state != 0 && state != 1 && state != 8) return true;
    }
    return false;
}

void ActivateZoneChest(ZoneChestEntry* chest, int ownerIndex, bool reset, bool force)
{
    if (chest->state == 1)
    {
        chest->state = 2;
        chest->ownerIndex = ownerIndex;
        chest->timer = 0;
    }
    else if (force)
    {
        chest->state = 2;
        chest->ownerIndex = ownerIndex;
        chest->timer = 0;
    }
    if (reset) chest->unknown_18 = 0;
}
