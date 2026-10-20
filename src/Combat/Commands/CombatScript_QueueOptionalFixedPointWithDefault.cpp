#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned int CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" unsigned int _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" unsigned int _fmul(unsigned int, unsigned int);
extern "C" int _ffix(unsigned int);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216CD28; symbol: func_ov000_0216cd28; size: 0x68.
extern "C" int CombatScript_QueueOptionalFixedPointWithDefault(void *parameter, int threshold) {
    char *entry = _ZN13SafeAllocator8AllocateEj(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[2], 0xc);
    *(unsigned int *)entry = 0x7b;
    int value = 0xf000;
    if (threshold > 0) {
        unsigned int bits = _ZNK6Script9Parameter7ToFloatEv(parameter);
        value = _ffix(_fmul(0x45800000, bits));
    }
    *(int *)(entry + 8) = value;
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
