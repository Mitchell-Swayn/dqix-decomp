#include <globaldefs.h>
ARM
extern "C" unsigned char data_ov000_02184264[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216C384; symbol: func_ov000_0216c384; size: 0x68.
extern "C" int Script_AllocateTypeNinetySevenEntry(const void* parameters) {
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned)*(void**)(data_ov000_02184264 + 8), 0x14);
    *(unsigned*)entry = 0;
    *(unsigned*)(entry + 4) = 0;
    *(unsigned*)entry = 0x61;
    *(unsigned short*)(entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameters);
    *(unsigned*)(entry + 0xC) = (unsigned)_ZNK6Script9Parameter5ToIntEv((char*)parameters + 8);
    *(unsigned*)(entry + 0x10) = (unsigned)_ZNK6Script9Parameter5ToIntEv((char*)parameters + 0x10);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
