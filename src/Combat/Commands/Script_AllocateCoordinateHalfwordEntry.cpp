#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage;
extern "C" void *_ZN13SafeAllocator8AllocateEj(void *, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216B8AC; symbol: func_ov000_0216b8ac; size: 0x54.
extern "C" bool Script_AllocateCoordinateHalfwordEntry(const void *parameter) {
    void *allocator = *(void **)((unsigned char *)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    void *entry = _ZN13SafeAllocator8AllocateEj(allocator, 0x0C);
    if (entry == 0) return false;
    *(unsigned int *)entry = 0;
    *(unsigned int *)((unsigned char *)entry + 4) = 0;
    *(unsigned int *)entry = 0x3F;
    *(int *)((unsigned char *)entry + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return true;
}
