#include "World/Zone3D.h"

// Original: arm9/main @ 0x0201777C; symbol: _ZN6Zone3D23GetContainerRenderEntryEi; size: 0x2C.
ZoneContainerRenderEntry* Zone3D::GetContainerRenderEntry(int index)
{
    if (index < 0 || unknown_476_ <= index) return NULL;
    return &unknown_478_[index];
}

// Original: arm9/main @ 0x020177A8; symbol: _ZN6Zone3D13GetChestEntryEi; size: 0x2C.
ZoneChestEntry* Zone3D::GetChestEntry(int index)
{
    if (index < 0 || numChests_ <= index) return NULL;
    return &unknown_47c_[index];
}
