#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216A1A4; symbol: func_ov000_0216a1a4; size: 0x64.
extern "C" int AllocateScriptValueWithOptionalFlag(const void *parameter, int argumentCount) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0x10);
    *(unsigned *)record = 8;
    *(int *)(record + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    record[0xc] = 0;
    if (argumentCount >= 2) record[0xc] = (unsigned char)_ZNK6Script9Parameter5ToIntEv((const char *)parameter + 8);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
