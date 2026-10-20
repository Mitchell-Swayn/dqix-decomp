#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x2290d40; symbol: data_ov031_02290d40.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage;
extern "C" int IPC_SendNormalizedBooleanModeCommand(int mode);
// Original: arm9/ov031 @ 0x0223D704; symbol: func_ov031_0223d704; size: 0x7C.
extern "C" void System_SynchronizeIpcModeWithHardwareFlag() {
 if (WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage) {
 if (((*(volatile unsigned short*)0x027fffa8 & 0x8000) >> 15) == 0) {
 if (!IPC_SendNormalizedBooleanModeCommand(1)) return;
 WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage=0;
 }
 } else {
 if (((*(volatile unsigned short*)0x027fffa8 & 0x8000) >> 15) != 0) {
 if (IPC_SendNormalizedBooleanModeCommand(0)) WfcUtilityAreButtonsPressed_UnknownRoleZeroInitializedStorage=1;
 }
 }
}
