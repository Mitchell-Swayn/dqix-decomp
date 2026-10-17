#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216A8D8; symbol: func_ov000_0216a8d8; size: 0x5C.
extern "C" int AllocateScriptBytePairRecord(const void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xc);
    *(unsigned *)record = 0;
    *(unsigned *)(record + 4) = 0;
    *(unsigned *)record = 0x16;
    record[8] = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    record[9] = (unsigned char)_ZNK6Script9Parameter5ToIntEv((const char *)parameter + 8);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
