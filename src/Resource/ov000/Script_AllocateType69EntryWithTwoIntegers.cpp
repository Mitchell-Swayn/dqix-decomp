#include <globaldefs.h>
ARM
extern unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216BA68; symbol: func_ov000_0216ba68; size: 0x60.
extern "C" int Script_AllocateType69EntryWithTwoIntegers(const void *parameter) {
    char *allocator = *(char **)(data_ov000_02184264 + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    if (entry == 0) return 0;
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x45;
    *(short *)(entry + 8) = (short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(short *)(entry + 0xA) = (short)_ZNK6Script9Parameter5ToIntEv((char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
