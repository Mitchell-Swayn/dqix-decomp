#include <globaldefs.h>
ARM
extern "C" void *_Z25AllocateVRAMStagingMemoryj(unsigned int);
// Original: arm9/ov017 @ 0x02199684; symbol: func_ov017_02199684; size: 0x38.
extern "C" void Ov017_AllocateVRAMStagingEntries(char *entries, int count, unsigned int size) {
    int i;
    for (i = 0; i < count; i++) {
        *(void **)(entries + i * 0x20 + 0x14) = _Z25AllocateVRAMStagingMemoryj(size);
    }
}
