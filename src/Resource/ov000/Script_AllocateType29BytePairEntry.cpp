#include <globaldefs.h>
ARM

struct IntegerParameterView;
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
extern "C" unsigned char data_ov000_02184264[];

// Original: arm9/ov000 @ 0x0216AE70; symbol: func_ov000_0216ae70; size: 0x60.
extern "C" int Script_AllocateType29BytePairEntry(const IntegerParameterView *parameter) {
    void *allocator = *(void **)(data_ov000_02184264 + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x29;
    entry[9] = _ZNK6Script9Parameter5ToIntEv(parameter) - 0x1a;
    entry[8] = _ZNK6Script9Parameter5ToIntEv((const char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
