#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(void* allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void* parameter);
extern "C" void Overlay_EnqueueLinkedNode(void* entry);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216B754; symbol: func_ov000_0216b754; size: 0x64.
extern "C" int Script_AllocateTaggedIntegerEntry3A(const void* parameter, int useParameter) {
    void* allocator = *(void**)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    volatile unsigned* entry = (volatile unsigned*)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    if (entry == 0)
        return 0;
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x3a;
    int value;
    if (useParameter == 0)
        value = 1;
    else
        value = _ZNK6Script9Parameter5ToIntEv(parameter);
    entry[2] = value;
    Overlay_EnqueueLinkedNode((void*)entry);
    return 1;
}
