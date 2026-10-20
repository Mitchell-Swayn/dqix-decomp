#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216C28C; symbol: func_ov000_0216c28c; size: 0x38.
extern "C" int Network_AllocateAndEnqueueTypeNinetyFourNode(void) {
    char *node = _ZN13SafeAllocator8AllocateEj((unsigned)*(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    *(unsigned *)node = 0;
    *(unsigned *)(node + 4) = 0;
    *(unsigned *)node = 0x5e;
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
