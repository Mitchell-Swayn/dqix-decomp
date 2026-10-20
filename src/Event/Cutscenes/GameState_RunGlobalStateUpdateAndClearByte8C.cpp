#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x21658d8; symbol: data_ov001_021658d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char ScriptDisplayEventText_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/ov001 @ 0x21658b8; symbol: data_ov001_021658b8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" char EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[];
extern "C" void Script_ClearTextTable(void *state);
// Original: arm9/ov001 @ 0x0215E27C; symbol: GameState_RunGlobalStateUpdateAndClearByte8C; size: 0x28.
// Calls the global-state routine with data_ov001_021658d8, clears byte +0x8c of data_ov001_021658b8, and returns one.
extern "C" unsigned GameState_RunGlobalStateUpdateAndClearByte8C(void) {
    Script_ClearTextTable(ScriptDisplayEventText_UnknownRoleZeroInitializedStorage);
    EventSetAllocatorSlot_UnknownRoleZeroInitializedStorage[0x8c] = 0;
    return 1;
}
