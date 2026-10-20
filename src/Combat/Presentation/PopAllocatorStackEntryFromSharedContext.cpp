#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned char CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" void PopAllocatorStack(void *);
// Original: arm9/ov025 @ 0x021E4EC8; symbol: PopAllocatorStackEntryFromSharedContext; size: 0x1C.
// Loads the allocator-stack pointer at shared data +0xC and pops one stack entry.
extern "C" int PopAllocatorStackEntryFromSharedContext(void) {
    PopAllocatorStack(*(void **)((unsigned char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc));
    return 1;
}
