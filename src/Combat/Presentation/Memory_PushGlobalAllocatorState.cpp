#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned int CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[];
extern "C" void Memory_PushAllocatorState(void *);

// Original: arm9/ov025 @ 0x021E4EAC; symbol: func_ov025_021e4eac; size: 0x1C.
extern "C" int Memory_PushGlobalAllocatorState(void) {
    Memory_PushAllocatorState((void *)CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage[3]);
    return 1;
}
