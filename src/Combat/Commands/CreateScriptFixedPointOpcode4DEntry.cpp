#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" void *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" unsigned int _ZNK6Script9Parameter7ToFloatEv(const void *);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216BC54; symbol: CreateScriptFixedPointOpcode4DEntry; size: 0x58.
// Allocates a 0xC-byte entry tagged 0x4D, stores script float times 4096 as an integer, submits it, and returns success.
extern "C" int CreateScriptFixedPointOpcode4DEntry(const void *parameter) {
    unsigned char *record = (unsigned char *)_ZN13SafeAllocator8AllocateEj((unsigned int)*(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    *(unsigned int *)record = 0x4d;
    *(int *)(record + 8) = _ffix(_fmul(0x45800000, _ZNK6Script9Parameter7ToFloatEv(parameter)));
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
