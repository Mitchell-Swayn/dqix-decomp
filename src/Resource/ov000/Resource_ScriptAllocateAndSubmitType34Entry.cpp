#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int allocator, unsigned int size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
extern "C" unsigned char data_ov000_02184264[];

// Original: arm9/ov000 @ 0x0216B408; symbol: func_ov000_0216b408; size: 0x5C.
extern "C" int Resource_ScriptAllocateAndSubmitType34Entry(const void *parameter) {
    unsigned int allocator = *(unsigned int *)(data_ov000_02184264 + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x34;
    entry[8] = _ZNK6Script9Parameter5ToIntEv(parameter);
    entry[9] = _ZNK6Script9Parameter5ToIntEv((const char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
