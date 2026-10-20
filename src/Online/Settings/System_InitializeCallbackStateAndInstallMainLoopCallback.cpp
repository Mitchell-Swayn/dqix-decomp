#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern unsigned char WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_StopSetupTaskAndQueueDisplayExit(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void), void *, int);
// Original: arm9/ov031 @ 0x0222B420; symbol: func_ov031_0222b420; size: 0x30.
extern "C" void System_InitializeCallbackStateAndInstallMainLoopCallback(void) {
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage = 0;
    WfcUtility_SetMainLoopCallback(WfcUtility_StopSetupTaskAndQueueDisplayExit, &WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage, 0);
}
