#include <globaldefs.h>
ARM
extern unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" unsigned int _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216BE00; symbol: func_ov000_0216be00; size: 0x58.
extern "C" int Script_AllocateType84EntryFromFloatParameter(void *parameter) {
    char *allocator = *(char **)(data_ov000_02184264 + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    *(unsigned int *)entry = 0x54;
    *(short *)(entry + 8) = (short)_ffix(_fmul(0x45800000, _ZNK6Script9Parameter7ToFloatEv(parameter)));
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
