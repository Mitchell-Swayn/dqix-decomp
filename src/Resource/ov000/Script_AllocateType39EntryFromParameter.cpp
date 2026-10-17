#include <globaldefs.h>
ARM
extern unsigned char data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216ADCC; symbol: func_ov000_0216adcc; size: 0x50.
extern "C" int Script_AllocateType39EntryFromParameter(const void *parameter) {
    char *allocator = *(char **)(data_ov000_02184264 + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x27;
    entry[8] = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
