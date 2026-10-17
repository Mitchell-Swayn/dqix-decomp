#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(void* allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void* parameter);
extern "C" void Overlay_EnqueueLinkedNode(void* entry);
extern "C" char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216C624; symbol: func_ov000_0216c624; size: 0x5C.
extern "C" int Script_AllocateTaggedByteAndHalfwordEntry(void* parameter) {
    void* allocator = *(void**)(data_ov000_02184264 + 8);
    volatile unsigned* entry = (volatile unsigned*)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x6c;
    *(volatile unsigned char*)((char*)entry + 8) = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(volatile unsigned short*)((char*)entry + 0xa) = (unsigned short)_ZNK6Script9Parameter5ToIntEv((char*)parameter + 8);
    Overlay_EnqueueLinkedNode((void*)entry);
    return 1;
}
