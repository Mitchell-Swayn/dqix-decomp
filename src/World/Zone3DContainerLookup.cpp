#include "World/Zone3D.h"

ZoneContainerRenderEntry* Zone3D::GetContainerRenderEntry(int index)
{
    if (index < 0 || unknown_476_ <= index) return NULL;
    return &unknown_478_[index];
}

ZoneChestEntry* Zone3D::GetChestEntry(int index)
{
    if (index < 0 || numChests_ <= index) return NULL;
    return &unknown_47c_[index];
}
