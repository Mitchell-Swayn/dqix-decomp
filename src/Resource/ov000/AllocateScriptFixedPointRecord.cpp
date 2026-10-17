#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216CE5C; symbol: func_ov000_0216ce5c; size: 0x64.
extern "C" int AllocateScriptFixedPointRecord(void *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xc);
    *(unsigned *)record = 0x7f;
    *(short *)(record + 8) = (short)(int)(_ZNK6Script9Parameter7ToFloatEv(parameter) * 4096.0f);
    *(short *)(record + 0xa) = (short)_ZNK6Script9Parameter5ToIntEv((char *)parameter + 8);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
