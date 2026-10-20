#include <globaldefs.h>
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21658d8; symbol: data_ov001_021658d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" unsigned char ScriptDisplayEventText_UnknownRoleZeroInitializedStorage[];
extern "C" void Script_BuildOwnedTextTable(void*, void*, unsigned, unsigned);
// Original: arm9/ov001 @ 0x0215ACF8; symbol: func_ov001_0215acf8; size: 0x34.
extern "C" void Script_InvokeGlobalCommandAndClearStatus(unsigned first, unsigned second) {
    Script_BuildOwnedTextTable(ScriptDisplayEventText_UnknownRoleZeroInitializedStorage, *(void**)EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage, first, second);
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0x8c] = 0;
}
