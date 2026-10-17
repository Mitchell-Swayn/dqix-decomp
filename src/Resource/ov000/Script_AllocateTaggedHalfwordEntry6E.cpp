#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(void* allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void* parameter);
extern "C" void Overlay_EnqueueLinkedNode(void* entry);
extern "C" char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216C6D0; symbol: func_ov000_0216c6d0; size: 0x50.
extern "C" int Script_AllocateTaggedHalfwordEntry6E(const void* parameter) {
    void* allocator = *(void**)(data_ov000_02184264 + 8);
    volatile unsigned* entry = (volatile unsigned*)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x6e;
    *(volatile unsigned short*)((char*)entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode((void*)entry);
    return 1;
}
