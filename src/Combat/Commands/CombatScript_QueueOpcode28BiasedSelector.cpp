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
// Original: arm9/ov000 @ 0x0216AE1C; symbol: func_ov000_0216ae1c; size: 0x54.
extern "C" int CombatScript_QueueOpcode28BiasedSelector(const void *parameter) {
    char *allocator = *(char **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    char *entry = _ZN13SafeAllocator8AllocateEj((unsigned)allocator, 0xC);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x28;
    entry[8] = (unsigned char)(_ZNK6Script9Parameter5ToIntEv(parameter) - 0x1A);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
