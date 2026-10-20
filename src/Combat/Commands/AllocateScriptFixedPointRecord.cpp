#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216CE5C; symbol: func_ov000_0216ce5c; size: 0x64.
extern "C" int AllocateScriptFixedPointRecord(void *parameter) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char *record = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xc);
    *(unsigned *)record = 0x7f;
    *(short *)(record + 8) = (short)(int)(_ZNK6Script9Parameter7ToFloatEv(parameter) * 4096.0f);
    *(short *)(record + 0xa) = (short)_ZNK6Script9Parameter5ToIntEv((char *)parameter + 8);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
