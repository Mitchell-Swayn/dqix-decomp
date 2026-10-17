#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
extern "C" unsigned char data_ov000_02184264[];

// Original: arm9/ov000 @ 0x0216C23C; symbol: func_ov000_0216c23c; size: 0x50.
extern "C" int Script_AllocateType5DHalfwordEntry(const void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x5d;
    *(unsigned short *)(entry + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
