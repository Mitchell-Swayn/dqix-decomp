#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void* entry);
// Original: arm9/ov000 @ 0x0216CF84; symbol: func_ov000_0216cf84; size: 0x50.
extern "C" int Script_AllocateTypeOneHundredThirtyTwoEntry(const void* parameter, int count) {
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned)*(void**)(data_ov000_02184264 + 8), 0xC);
    *(unsigned*)entry = 0x84;
    if (count >= 1)
        *(unsigned char*)(entry + 8) = (unsigned char)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
