#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216BC00; symbol: func_ov000_0216bc00; size: 0x54.
extern "C" int Script_TryAllocateTypedParameterEntry(void* parameter) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_ov000_02184264 + 8), 0xc);
    if (!node) return 0;
    *(unsigned*)node = 0;
    *(unsigned*)(node + 4) = 0;
    *(unsigned*)node = 0x4c;
    *(node + 8) = (char)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
