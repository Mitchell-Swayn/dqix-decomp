#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned int EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov001 @ 0x0215AAA8; symbol: func_ov001_0215aaa8; size: 0x10.
extern "C" void Event_SetAllocatorSlot(unsigned int index, unsigned int value) {
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[index] = value;
}
