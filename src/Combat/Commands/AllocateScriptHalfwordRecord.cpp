#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216B700; symbol: func_ov000_0216b700; size: 0x54.
extern "C" int AllocateScriptHalfwordRecord(const void *parameter) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xc);
    if (record == 0) return 0;
    *(unsigned *)record = 0;
    *(unsigned *)(record + 4) = 0;
    *(unsigned *)record = 0x39;
    *(short *)(record + 8) = (short)_ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
