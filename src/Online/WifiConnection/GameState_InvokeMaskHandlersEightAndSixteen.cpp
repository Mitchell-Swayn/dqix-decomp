#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
extern "C" void GameState_ClearMaskBitAndInvokeHandler(unsigned, int, int);
// Original: arm9/ov031 @ 0x022135BC; symbol: func_ov031_022135bc; size: 0x38.
extern "C" void GameState_InvokeMaskHandlersEightAndSixteen(void) {
    GameState_ClearMaskBitAndInvokeHandler(8, *(int *)(NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage + 8), 0xC);
    GameState_ClearMaskBitAndInvokeHandler(0x10, *(int *)(NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage + 0x10), 0xD18);
}
