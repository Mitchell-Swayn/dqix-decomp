#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
extern "C" void *memset(void *, int, unsigned int);
typedef void *(*AllocatorFn)(unsigned int);
// Original: arm9/ov031 @ 0x0222288C; symbol: func_ov031_0222288c; size: 0x24.
extern "C" void *Memory_AllocateZeroedArray(unsigned int elementSize, unsigned int count) {
    unsigned int size = elementSize * count;
    AllocatorFn allocate = *(AllocatorFn *)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage + 4);
    void *result = allocate(size);
    if (result)
        memset(result, 0, size);
    return result;
}
