#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned char *_ZN13SafeAllocator8AllocateEj(void *, unsigned);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" float _fmul(float, float);
extern "C" int _ffix(float);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x02169FA4; symbol: func_ov000_02169fa4; size: 0x74.
extern "C" int CombatScript_QueueOpcode06FixedPointPair(void *script) {
    unsigned char *entry = _ZN13SafeAllocator8AllocateEj(*(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 12);
    *(unsigned int *)entry = 6;
    *(unsigned short *)(entry + 8) = (unsigned short)_ffix(_fmul(4096.0f, _ZNK6Script9Parameter7ToFloatEv(script)));
    *(unsigned short *)(entry + 10) = (unsigned short)_ffix(_fmul(4096.0f, _ZNK6Script9Parameter7ToFloatEv((unsigned char *)script + 8)));
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
