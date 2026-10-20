#include <globaldefs.h>
ARM
extern "C" char *_ZN13SafeAllocator8AllocateEj(unsigned int, unsigned int);
extern "C" float _ZNK6Script9Parameter7ToFloatEv(void *);
extern "C" float _fmul(float, float);
extern "C" int _ffix(float);
extern "C" void Overlay_EnqueueLinkedNode(void *);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov000 @ 0x0216BF40; symbol: Resource_QueueScriptFixedPointRecord57; size: 0x64.
// Allocates a 12-byte type-0x57 record, converts a script parameter to float, scales it by 4096, stores the fixed halfword, links the entry, and returns 1.
extern "C" int CombatScript_QueueOpcode57FixedPointHalfword(void *parameter) {
    void *allocator = *(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8);
    unsigned char *entry = (unsigned char *)_ZN13SafeAllocator8AllocateEj((unsigned int)allocator, 0xc);
    *(unsigned int *)entry = 0;
    *(unsigned int *)(entry + 4) = 0;
    *(unsigned int *)entry = 0x57;
    float value = _ZNK6Script9Parameter7ToFloatEv(parameter);
    *(short *)(entry + 8) = (short)_ffix(_fmul(4096.0f, value));
    Overlay_EnqueueLinkedNode(entry);
    return 1;
}
