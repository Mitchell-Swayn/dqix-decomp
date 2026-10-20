#include <globaldefs.h>
ARM
extern "C" void VectorizedMemset(void *, int, unsigned int);
extern "C" void *_ZN13HPXEAllocator16CreateAtLocationEPvjt(void *, unsigned, unsigned short);
extern "C" void DisableInterruptsAndHaltForever(void);
// Original data: arm9/ov031 @ 0x2290d3c; symbol: data_ov031_02290d3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0223CE9C; symbol: func_ov031_0223ce9c; size: 0x40.
extern "C" void Memory_InitializeHPXEAllocatorAtLocation(void *location) {
    VectorizedMemset(location, 0, 0x40000);
    void *allocator = _ZN13HPXEAllocator16CreateAtLocationEPvjt(location, 0x40000, 0);
    MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage = allocator;
    if (allocator == 0) DisableInterruptsAndHaltForever();
}
