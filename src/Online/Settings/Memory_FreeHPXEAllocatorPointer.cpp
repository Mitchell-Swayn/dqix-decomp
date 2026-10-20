#include <globaldefs.h>
ARM
extern "C" unsigned int _Z25DisableSpecificInterruptsj(unsigned int);
extern "C" void _Z24EnableSpecificInterruptsj(unsigned int);
extern "C" void _ZN13HPXEAllocator4FreeEPv(void *, void *);
// Original data: arm9/ov031 @ 0x2290d3c; symbol: data_ov031_02290d3c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0223CFB4; symbol: func_ov031_0223cfb4; size: 0x3C.
extern "C" void Memory_FreeHPXEAllocatorPointer(void *ptr) {
    unsigned int state = _Z25DisableSpecificInterruptsj(1);
    if (ptr == 0) return;
    _ZN13HPXEAllocator4FreeEPv(*(void **)MemoryAllocateSharedHeapOrHalt_UnknownRoleZeroInitializedStorage, ptr);
    _Z24EnableSpecificInterruptsj(state);
}
