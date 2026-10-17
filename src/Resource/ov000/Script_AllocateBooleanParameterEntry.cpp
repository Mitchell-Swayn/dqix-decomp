#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216CC88; symbol: func_ov000_0216cc88; size: 0x50.
extern "C" int Script_AllocateBooleanParameterEntry(void* parameter) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_ov000_02184264 + 8), 0xc);
    *(unsigned*)node = 0x77;
    *(node + 8) = (char)(_ZNK6Script9Parameter5ToIntEv(parameter) != 0);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
