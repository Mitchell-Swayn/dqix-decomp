#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216A300; symbol: func_ov000_0216a300; size: 0x50.
extern "C" int AllocateScriptParameterRecord(const void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xc);
    *(unsigned *)record = 0xa;
    int value = _ZNK6Script9Parameter5ToIntEv(parameter);
    *(short *)(record + 8) = (short)value;
    if (*(unsigned short *)(record + 8) != 0) Overlay_EnqueueLinkedNode(record);
    return 1;
}
