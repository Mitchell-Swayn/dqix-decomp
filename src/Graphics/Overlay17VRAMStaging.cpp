#include "Graphics/VRAMStaging.h"

struct Overlay17VRAMStagingEntry
{
    unsigned char unknown_00[0x14];
    const void* allocation_14;
    unsigned char unknown_18[0x8];
};

extern "C" void func_ov017_021a5b08(Overlay17VRAMStagingEntry* entries, int count)
{
    for (int i = 0; i < count; ++i)
    {
        const void* allocation = entries[i].allocation_14;
        entries[i].allocation_14 = 0;
        if (allocation != 0)
            FreeVRAMStagingMemory(allocation);
    }
}
