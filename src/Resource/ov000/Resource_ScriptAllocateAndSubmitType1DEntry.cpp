#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int allocator, unsigned int size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
extern "C" unsigned char data_ov000_02184264[];

// Original: arm9/ov000 @ 0x0216AB74; symbol: func_ov000_0216ab74; size: 0x50.
extern "C" int Resource_ScriptAllocateAndSubmitType1DEntry(const void *parameter) {
    unsigned int allocator = *(unsigned int *)(data_ov000_02184264 + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x1d;
    *(unsigned int *)(entry + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
