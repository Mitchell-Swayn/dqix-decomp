// Clears the pointer at offset 0x14 in each 0x20-byte entry and releases each nonnull value through the established VRAM staging API; entry meaning is unknown.
#include "Graphics/VRAMStaging.h"
// Original: arm9/ov017 @ 0x021A5B08; symbol: func_ov017_021a5b08; size: 0x40.
extern "C" void Field_ReleasePromptBackgroundStagingBuffers(unsigned char* entries, int count)
{
    int i;
    for (i = 0; i < count; ++i) {
        void** slot = (void**)(entries + i * 0x20 + 0x14);
        void* allocation = *slot;
        *slot = 0;
        if (allocation)
            FreeVRAMStagingMemory(allocation);
    }
}
