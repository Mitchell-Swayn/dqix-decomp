#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216BA68; symbol: func_ov000_0216ba68; size: 0x60.
extern "C" int CombatScript_TryQueueOpcode45HalfwordPair(const void *parameter) {
    char *allocator = *(char **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    if (entry == 0) return 0;
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x45;
    *(short *)(entry + 8) = (short)_ZNK6Script9Parameter5ToIntEv(parameter);
    *(short *)(entry + 0xA) = (short)_ZNK6Script9Parameter5ToIntEv((char *)parameter + 8);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
