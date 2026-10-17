#include <globaldefs.h>
ARM
extern "C" unsigned _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(void*);
extern "C" unsigned data_ov001_021658b8[];
// Original: arm9/ov001 @ 0x0215AA14; symbol: func_ov001_0215aa14; size: 0x48.
extern "C" void Memory_ResetAllocatorCache(void* allocator) {
    for (int i = 0; i < 8; ++i) data_ov001_021658b8[i] = 0;
    if (!allocator) return;
    _ZNK13SafeAllocator24GetMaxPossibleAllocationEv(allocator);
    data_ov001_021658b8[0] = (unsigned)allocator;
}
