#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int allocator, unsigned int size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov000 @ 0x0216AB74; symbol: func_ov000_0216ab74; size: 0x50.
extern "C" int Resource_ScriptAllocateAndSubmitType1DEntry(const void *parameter) {
    unsigned int allocator = *(unsigned int *)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x1d;
    *(unsigned int *)(entry + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
