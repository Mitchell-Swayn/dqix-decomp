#include <globaldefs.h>
ARM
extern "C" char* _ZN13SafeAllocator8AllocateEj(unsigned, unsigned);
extern "C" void Overlay_EnqueueLinkedNode(void*);
// Original data: arm9/ov000 @ 0x2184264; symbol: data_ov000_02184264.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" unsigned char CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov000 @ 0x02169BB4; symbol: func_ov000_02169bb4; size: 0x3C.
extern "C" void Combat_AllocateAndRegisterOwnerEntry(void* owner) {
    char* node = _ZN13SafeAllocator8AllocateEj(*(unsigned*)(CreateScriptOpcode7CEntry_UnknownRoleZeroInitializedStorage + 8), 8);
    if (!node) return;
    *(unsigned*)node = 0;
    *(unsigned*)(node + 4) = 0;
    *(void**)node = owner;
    Overlay_EnqueueLinkedNode(node);
}
