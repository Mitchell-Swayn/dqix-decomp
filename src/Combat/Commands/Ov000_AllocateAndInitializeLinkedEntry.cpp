#include <globaldefs.h>
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216B6AC; symbol: func_ov000_0216b6ac; size: 0x54.
extern "C" int Ov000_AllocateAndInitializeLinkedEntry(const void *parameter) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    unsigned int *entry = (unsigned int *)_ZN13SafeAllocator8AllocateEj(allocator, 0x0c);
    if (entry == 0) return 0;
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x38;
    *(unsigned short *)(entry + 2) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
