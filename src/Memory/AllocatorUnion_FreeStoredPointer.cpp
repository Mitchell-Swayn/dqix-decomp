#include <globaldefs.h>
ARM
#pragma optimization_level 4
extern "C" {
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];
    void Memory_FreeThroughAllocatorUnion(void *,void *);
// Original: arm9/main @ 0x020998AC; symbol: func_020998ac; size: 0x18.
    void AllocatorUnion_FreeStoredPointer(void **p){
        Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,*p);
    }
}
