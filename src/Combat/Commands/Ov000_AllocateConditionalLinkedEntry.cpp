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
// Original: arm9/ov000 @ 0x0216D0A8; symbol: func_ov000_0216d0a8; size: 0x68.
extern "C" int Ov000_AllocateConditionalLinkedEntry(const void *parameter, int count) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    int *entry = (int *)_ZN13SafeAllocator8AllocateEj(allocator, 0x0c);
    entry[0] = 0;
    entry[1] = 0;
    entry[0] = 0x8b;
    short value = -1;
    if (count >= 1) value = (short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(short *)(entry + 2) = value;
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
