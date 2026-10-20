#include <globaldefs.h>
ARM
// Original: arm9/ov031 @ 0x0222D0E0; symbol: DispatchSharedStateCallback; size: 0xD8.
extern "C" int System_IsGlobalTaskAvailable(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned* a, unsigned* b);
extern "C" void WfcUtility_CreateSlidingDialog(unsigned, unsigned, unsigned, unsigned, unsigned);
extern "C" void WfcUtility_ReleaseWirelessTextEditor(void);
extern "C" void System_InstallModeCallbackWhenStateIsZero(void);
extern "C" void System_DispatchSharedByteStateAndInstallCallback(void);
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
// Original data: arm9/ov031 @ 0x2248eb4; symbol: data_ov031_02248eb4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 3e3d0e00100000004700000048000000ac5c2302dc5c2302.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int SystemDispatchSelectedSharedCallback_UnknownRoleProcedureReferenceRecords[];
extern "C" void WfcUtility_DispatchWirelessTextValidationResult(void)
{
    volatile unsigned values[2];
    values[0] = SystemDispatchSelectedSharedCallback_UnknownRoleProcedureReferenceRecords[2];
    values[1] = SystemDispatchSelectedSharedCallback_UnknownRoleProcedureReferenceRecords[3];
    unsigned result = System_IsGlobalTaskAvailable();
    if (result != 0)
        return;
    unsigned state = *(unsigned char*)(*(unsigned int*)(&WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage) + 0x2a);
    if (state == 0) {
        WfcUtility_SetMainLoopCallback(WfcUtility_ReleaseWirelessTextEditor);
        return;
    }
    if (state == 2) {
        WfcUtility_CreateSlidingDialog(6, 3, 1, (unsigned)-1, 0);
        WfcUtility_SetMainLoopCallback(System_InstallModeCallbackWhenStateIsZero);
        return;
    }
    unsigned sharedIndex;
    WfcUtility_GetScreenOperationArguments(0, &sharedIndex);
    WfcUtility_CreateSlidingDialog(values[sharedIndex], 2, 1, (unsigned)-1, 0);
    WfcUtility_SetMainLoopCallback(System_DispatchSharedByteStateAndInstallCallback);
}
