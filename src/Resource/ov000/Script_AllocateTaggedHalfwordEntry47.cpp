#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(void* allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void* parameter);
extern "C" void Overlay_EnqueueLinkedNode(void* entry);
extern "C" char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216BB1C; symbol: func_ov000_0216bb1c; size: 0x54.
extern "C" int Script_AllocateTaggedHalfwordEntry47(const void* parameter) {
    void* allocator = *(void**)(data_ov000_02184264 + 8);
    volatile unsigned* entry = (volatile unsigned*)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    if (entry == 0) return 0;
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x47;
    *(volatile unsigned short*)((char*)entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode((void*)entry);
    return 1;
}
