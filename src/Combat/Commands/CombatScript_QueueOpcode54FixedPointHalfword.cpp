#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" unsigned int _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216BE00; symbol: func_ov000_0216be00; size: 0x58.
extern "C" int CombatScript_QueueOpcode54FixedPointHalfword(void *parameter) {
    char *allocator = *(char **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    *(unsigned int *)entry = 0x54;
    *(short *)(entry + 8) = (short)_ffix(_fmul(0x45800000, _ZNK6Script9Parameter7ToFloatEv(parameter)));
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
