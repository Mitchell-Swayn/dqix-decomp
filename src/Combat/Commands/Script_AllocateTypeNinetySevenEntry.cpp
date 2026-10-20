#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216C384; symbol: func_ov000_0216c384; size: 0x68.
extern "C" int Script_AllocateTypeNinetySevenEntry(const void* parameters) {
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned)*(void**)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0x14);
    *(unsigned*)entry = 0;
    *(unsigned*)(entry + 4) = 0;
    *(unsigned*)entry = 0x61;
    *(unsigned short*)(entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameters);
    *(unsigned*)(entry + 0xC) = (unsigned)_ZNK6Script9Parameter5ToIntEv((char*)parameters + 8);
    *(unsigned*)(entry + 0x10) = (unsigned)_ZNK6Script9Parameter5ToIntEv((char*)parameters + 0x10);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
