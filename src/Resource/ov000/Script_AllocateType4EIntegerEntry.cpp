#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
extern "C" unsigned char data_ov000_02184264[];

// Original: arm9/ov000 @ 0x0216BCAC; symbol: func_ov000_0216bcac; size: 0x44.
extern "C" int Script_AllocateType4EIntegerEntry(const void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0x4e;
    *(int *)(entry + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
