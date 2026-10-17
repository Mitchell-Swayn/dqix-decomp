#include <globaldefs.h>
extern "C" char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216B6AC; symbol: func_ov000_0216b6ac; size: 0x54.
extern "C" int Ov000_AllocateAndInitializeLinkedEntry(const void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    unsigned int *entry = (unsigned int *)_ZN13SafeAllocator8AllocateEj(allocator, 0x0c);
    if (entry == 0) return 0;
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x38;
    *(unsigned short *)(entry + 2) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
