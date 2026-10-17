#include <globaldefs.h>
ARM
extern "C" unsigned int data_ov000_02184264[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
struct ScriptParameter { unsigned char data[8]; };
// Original: arm9/ov000 @ 0x0216B204; symbol: func_ov000_0216b204; size: 0x68.
extern "C" int Script_AllocateTaggedBytePairHalfwordEntry(ScriptParameter *parameters) {
    char *entry = _ZN13SafeAllocator8AllocateEj(data_ov000_02184264[2], 0xc);
    *(unsigned int *)(entry + 0) = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)(entry + 0) = 0x2f;
    entry[8] = _ZNK6Script9Parameter5ToIntEv(parameters);
    entry[9] = _ZNK6Script9Parameter5ToIntEv((char *)parameters + 8);
    *(short *)(entry + 0xa) = _ZNK6Script9Parameter5ToIntEv((char *)parameters + 0x10);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
