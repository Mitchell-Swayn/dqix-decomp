#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" unsigned _ZNK6Script9Parameter7ToFloatEv(void*);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" unsigned _fmul(unsigned, unsigned);
extern "C" int _ffix(void);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216C7A0; symbol: func_ov000_0216c7a0; size: 0x64.
extern "C" int Script_AllocateScaledFloatParameterEntry(void* parameter) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    *(unsigned*)node = 0x71;
    unsigned value = _ZNK6Script9Parameter7ToFloatEv(parameter);
    _fmul(0x45800000, value);
    *(unsigned short*)(node + 0xa) = (unsigned short)_ffix();
    *(unsigned short*)(node + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv((char*)parameter + 8);
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
