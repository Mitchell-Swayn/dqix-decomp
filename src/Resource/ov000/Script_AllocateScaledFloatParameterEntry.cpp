#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" unsigned _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(void);
extern "C" void Overlay_EnqueueLinkedNode(void*);
extern "C" unsigned char data_ov000_02184264[];
// Original: arm9/ov000 @ 0x0216C7A0; symbol: func_ov000_0216c7a0; size: 0x64.
extern "C" int Script_AllocateScaledFloatParameterEntry(void* parameter) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(data_ov000_02184264 + 8), 0xc);
    *(unsigned*)node = 0x71;
    unsigned value = _ZNK6Script9Parameter7ToFloatEv(parameter);
    _fmul(0x45800000, value);
    *(unsigned short*)(node + 0xa) = (unsigned short)_ffix();
    *(unsigned short*)(node + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv((char*)parameter + 8);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
