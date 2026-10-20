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
// Original: arm9/ov000 @ 0x0216C0F4; symbol: Resource_QueueScriptByteRecord5A; size: 0x50.
// Allocates a 12-byte entry, tags it 0x5A, stores the converted script integer as a byte at +8, submits it, and returns success.
extern "C" int CombatScript_QueueOpcode5AByte(const void *parameter) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    unsigned char *record = (unsigned char *)_ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0xc);
    *(unsigned int *)record = 0;
    *(unsigned int *)(record + 4) = 0;
    *(unsigned int *)record = 0x5a;
    record[8] = _ZNK6Script9Parameter5ToIntEv(parameter);
    Overlay_EnqueueLinkedNode(record);
    return 1;
}
