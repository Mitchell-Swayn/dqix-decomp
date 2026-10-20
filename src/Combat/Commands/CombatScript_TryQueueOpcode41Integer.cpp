#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x0216B954; symbol: Memory_QueueScriptIntegerRecord41IfAllocated; size: 0x54.
// Allocates a 12-byte entry; if successful, tags it 0x41, stores the converted script integer, submits it, and returns success.
extern "C" int CombatScript_TryQueueOpcode41Integer(const void *parameter) {
    char *entry = _ZN13SafeAllocator8AllocateEj(*(unsigned int *)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    if (entry == 0) return 0;
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x41;
    *(unsigned int *)(entry + 8) = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
