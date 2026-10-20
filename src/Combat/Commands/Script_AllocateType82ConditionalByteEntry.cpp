#include <globaldefs.h>
ARM

extern "C" char *_ZN13SafeAllocator8AllocateEj(void *allocator, unsigned size);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *parameter);
extern "C" void Overlay_EnqueueLinkedNode(void *entry);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov000 @ 0x0216CF18; symbol: func_ov000_0216cf18; size: 0x58.
extern "C" int Script_AllocateType82ConditionalByteEntry(const void *parameter, int enabled) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0xc);
    *(unsigned int *)entry = 0x82;
    entry[8] = 1;
    if (enabled >= 1) entry[8] = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
