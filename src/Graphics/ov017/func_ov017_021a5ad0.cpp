#include <globaldefs.h>
ARM
extern "C" void *_Z25AllocateVRAMStagingMemoryj(unsigned int);
// Original: arm9/ov017 @ 0x021A5AD0; symbol: func_ov017_021a5ad0; size: 0x38.
extern "C" void func_ov017_021a5ad0(void *records, int count, unsigned int size) {
    for (int i = 0; i < count; ++i)
        *(void **)((char *)records + i * 0x20 + 0x14) = _Z25AllocateVRAMStagingMemoryj(size);
}
