#include <globaldefs.h>
extern "C" char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216D0A8; symbol: func_ov000_0216d0a8; size: 0x68.
extern "C" int Ov000_AllocateConditionalLinkedEntry(const void *parameter, int count) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    int *entry = (int *)_ZN13SafeAllocator8AllocateEj(allocator, 0x0c);
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x8b;
    short value = -1;
    if (count >= 1) value = (short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(short *)(entry + 2) = value;
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
