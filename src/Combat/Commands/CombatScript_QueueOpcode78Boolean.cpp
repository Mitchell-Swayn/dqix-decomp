#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" void *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void *);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original: arm9/ov000 @ 0x0216CCD8; symbol: Resource_QueueScriptBooleanRecord78; size: 0x50.
// Allocates a 12-byte entry, tags it 0x78, stores the converted script value as a boolean byte at +8, submits it, and returns success.
extern "C" int CombatScript_QueueOpcode78Boolean(const void *parameter) {
    unsigned char *record = (unsigned char *)_ZN13SafeAllocator8AllocateEj((unsigned int)*(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    *(unsigned int *)record = 0x78;
    record[8] = _ZNK6Script9Parameter5ToIntEv(parameter) != 0;
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
