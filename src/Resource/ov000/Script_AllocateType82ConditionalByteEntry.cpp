#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
extern "C" unsigned char data_ov000_02184264[];

// Original: arm9/ov000 @ 0x0216CF18; symbol: func_ov000_0216cf18; size: 0x58.
extern "C" int Script_AllocateType82ConditionalByteEntry(const void *parameter, int enabled) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0x82;
    entry[8] = 1;
    if (enabled >= 1) entry[8] = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
