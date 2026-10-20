#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290d3c; symbol: data_ov031_02290d3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage[];
extern "C" void _ZN13HPXEAllocator14RemoveFromTreeEv(void *);
// Original: arm9/ov031 @ 0x0223CEDC; symbol: func_ov031_0223cedc; size: 0x24.
extern "C" void Memory_RemoveGlobalHPXEAllocator(void) {
    _ZN13HPXEAllocator14RemoveFromTreeEv(*(void **)MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage);
    *(void **)MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage = 0;
}
