#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c40; symbol: data_ov031_02250c40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 25920 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned WfcUtilityRunSettingsModal_UnknownRoleZeroInitializedStorage;
extern "C" void RunModalCallbackLoopAndRestoreCurrentObject(void *, unsigned, unsigned, unsigned);
// Original: arm9/ov031 @ 0x0222708C; symbol: func_ov031_0222708c; size: 0x20.
extern "C" void WfcUtility_RunSettingsModal(unsigned a, unsigned b) {
    RunModalCallbackLoopAndRestoreCurrentObject(&WfcUtilityRunSettingsModal_UnknownRoleZeroInitializedStorage, a, b, a);
}
