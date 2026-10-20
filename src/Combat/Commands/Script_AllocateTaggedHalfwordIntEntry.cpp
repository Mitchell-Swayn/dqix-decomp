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
// Original: arm9/ov000 @ 0x0216C4A4; symbol: func_ov000_0216c4a4; size: 0x5C.
extern "C" bool Script_AllocateTaggedHalfwordIntEntry(const void *parameter) {
    void *allocator = *(void **)((unsigned char *)&CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj(allocator, 0x10);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x66;
    *(unsigned short *)(entry + 8) = (unsigned short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(int *)(entry + 0x0C) = _ZNK6Script9Parameter5ToIntEv((unsigned char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return true;
}
