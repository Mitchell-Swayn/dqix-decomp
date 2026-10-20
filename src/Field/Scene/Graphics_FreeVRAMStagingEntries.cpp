#include <globaldefs.h>
ARM
extern "C" void _Z21FreeVRAMStagingMemoryPKv(const void *);
// Original: arm9/ov017 @ 0x021996BC; symbol: func_ov017_021996bc; size: 0x40.
extern "C" void Graphics_FreeVRAMStagingEntries(void *entries, int count) {
    for (int i = 0; i < count; ++i) {
        void **slot = (void **)((char *)entries + i * 0x20 + 0x14);
        void *memory = *slot;
        *slot = 0;
        if (memory != 0) _Z21FreeVRAMStagingMemoryPKv(memory);
    }
}
