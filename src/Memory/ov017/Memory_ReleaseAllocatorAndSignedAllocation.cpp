#include <globaldefs.h>
ARM
extern "C" {
extern unsigned data_ov017_021d8474;
extern char data_02114e20[];
void* _ZNK13SafeAllocator18GetSignedAllocatorEv(void*);
void _ZN13SafeAllocator7DestroyEv(void*);
void Memory_FreeThroughAllocatorUnion(void*, void*);
// Original: arm9/ov017 @ 0x021C0160; symbol: func_ov017_021c0160; size: 0x44.
void Memory_ReleaseAllocatorAndSignedAllocation(void *p) {
    data_ov017_021d8474 = 0;
    void *allocator = _ZNK13SafeAllocator18GetSignedAllocatorEv((char *)p + 8);
    if (!allocator) return;
    _ZN13SafeAllocator7DestroyEv((char *)p + 8);
    Memory_FreeThroughAllocatorUnion(data_02114e20, allocator);
}
}
