#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264;
extern "C" void *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216C4A4; symbol: func_ov000_0216c4a4; size: 0x5C.
extern "C" bool Script_AllocateTaggedHalfwordIntEntry(const void *parameter) {
    void *allocator = *(void **)((unsigned char *)&data_ov000_02184264 + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0x10);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x66;
    *(unsigned short *)(entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(int *)(entry + 0x0C) = _ZNK6Script9Parameter5ToIntEv((unsigned char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return true;
}
