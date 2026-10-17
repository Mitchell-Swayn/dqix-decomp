#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216C5D4; symbol: func_ov000_0216c5d4; size: 0x50.
extern "C" int AllocateScriptIntegerRecord(const void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xc);
    *(unsigned *)record = 0;
    *(unsigned *)(record + 4) = 0;
    *(unsigned *)record = 0x6b;
    *(int *)(record + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
