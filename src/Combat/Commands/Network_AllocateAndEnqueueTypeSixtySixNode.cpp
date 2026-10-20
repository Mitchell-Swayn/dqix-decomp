#include <globaldefs.h>
ARM
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" int _ZNK6Script9Parameter5ToIntEv(const void*);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original: arm9/ov000 @ 0x0216B9A8; symbol: func_ov000_0216b9a8; size: 0x58.
extern "C" int Network_AllocateAndEnqueueTypeSixtySixNode(const void *parameter) {
    int value = _ZNK6Script9Parameter5ToIntEv(parameter);
    if (value < 0) return 1;
    char *node = _ZN13SafeAllocator8AllocateEj((unsigned)*(void **)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 0xc);
    if (!node) return 0;
    *(unsigned *)node = 0;
    *(unsigned *)(node + 4) = 0;
    *(unsigned *)node = 0x42;
    *(short *)(node + 8) = value;
    Overlay_EnqueueLinkedNode(node);
    return 1;
}
