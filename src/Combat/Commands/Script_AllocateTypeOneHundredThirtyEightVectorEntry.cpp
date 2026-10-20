#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void __clear(void*, unsigned);
extern "C" void _ZN6Script9Parameter9ToVec3fixEP8Vector3i(const void*, void*);
extern "C" void _ZN8Vector3iaSERKS_(void*, const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216D038; symbol: func_ov000_0216d038; size: 0x70.
extern "C" int Script_AllocateTypeOneHundredThirtyEightVectorEntry(const void* parameter) {
    char* entry = _ZN13SafeAllocator8AllocateEj((unsigned)*(void**)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0x14);
    *(unsigned*)entry = 0;
    *(unsigned*)(entry + 4) = 0;
    *(unsigned*)entry = 0x8A;
    int vector[3];
    __clear(vector, 0xC);
    _ZN6Script9Parameter9ToVec3fixEP8Vector3i(parameter, vector);
    _ZN8Vector3iaSERKS_(entry + 8, vector);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
