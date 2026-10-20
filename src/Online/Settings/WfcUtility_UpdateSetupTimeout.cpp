#include <globaldefs.h>
ARM
extern "C" void WfcUtility_QueueSetupCancelFromButtonOrSystemGate(void);
extern "C" void WfcUtility_RunEmptySetupUpdateHook(void);
extern "C" void WfcUtility_CancelSetupTaskAndBeginExit(void);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_StopSetupTaskAndQueueDisplayExit(void);
struct SetupCounter { unsigned short reserved; unsigned short value; };
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" volatile struct SetupCounter WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0222B3D4; symbol: func_ov031_0222b3d4; size: 0x4C.
extern "C" void WfcUtility_UpdateSetupTimeout(void) {
    WfcUtility_QueueSetupCancelFromButtonOrSystemGate();
    WfcUtility_RunEmptySetupUpdateHook();
    WfcUtility_CancelSetupTaskAndBeginExit();
    WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.value = WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.value + 1;
    if (WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage.value < 0x438) return;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_SetMainLoopCallback(WfcUtility_StopSetupTaskAndQueueDisplayExit);
}
