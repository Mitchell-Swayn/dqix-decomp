#include <globaldefs.h>
extern "C" char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216CDEC; symbol: func_ov000_0216cdec; size: 0x5C.
extern "C" int Ov000_AllocateOptionalLinkedEntry(const void *parameter, int count) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    int *entry = (int *)_ZN13SafeAllocator8AllocateEj(allocator, 0x0c);
    entry[0] = 0x7d;
    short value = -1;
    if (count > 0) value = (short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(short *)(entry + 2) = value;
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
