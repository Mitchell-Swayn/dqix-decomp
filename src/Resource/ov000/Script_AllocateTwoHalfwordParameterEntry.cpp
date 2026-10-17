#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216C514; symbol: func_ov000_0216c514; size: 0x5C.
extern "C" int Script_AllocateTwoHalfwordParameterEntry(void* parameter) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_ov000_02184264 + 8), 0xc);
    *(unsigned*)node = 0;
    *(unsigned*)(node + 4) = 0;
    *(unsigned*)node = 0x68;
    *(unsigned short*)(node + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(unsigned short*)(node + 0xa) = (unsigned short)_ZNK6Script9Parameter5ToIntEv((char*)parameter + 8);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
