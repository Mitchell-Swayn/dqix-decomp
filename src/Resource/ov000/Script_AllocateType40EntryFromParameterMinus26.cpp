#include <globaldefs.h>
ARM
extern unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216AE1C; symbol: func_ov000_0216ae1c; size: 0x54.
extern "C" int Script_AllocateType40EntryFromParameterMinus26(const void *parameter) {
    char *allocator = *(char **)(data_ov000_02184264 + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x28;
    entry[8] = (unsigned char)(_ZNK6Script9Parameter5ToIntEv(parameter) - 0x1A);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
