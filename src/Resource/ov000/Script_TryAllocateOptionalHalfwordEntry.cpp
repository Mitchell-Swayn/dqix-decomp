#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216C734; symbol: func_ov000_0216c734; size: 0x6C.
extern "C" int Script_TryAllocateOptionalHalfwordEntry(void* parameter, int enabled) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_ov000_02184264 + 8), 0xc);
    if (!node) return 0;
    *(unsigned*)node = 0;
    *(unsigned*)(node + 4) = 0;
    *(unsigned*)node = 0x70;
    unsigned short value = 0;
    if (enabled >= 1) value = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(unsigned short*)(node + 8) = value;
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
