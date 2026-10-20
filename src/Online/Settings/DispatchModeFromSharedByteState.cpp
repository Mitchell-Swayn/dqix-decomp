#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original data: arm9/ov031 @ 0x2290c6c; symbol: data_ov031_02290c6c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage[];
extern "C" void System_ResetSharedByteAndInstallMode8Callback(void);
// Original: arm9/ov031 @ 0x02229FE8; symbol: DispatchModeFromSharedByteState; size: 0x50.
// For shared byte state 0 or 1, selects mode 7 or 6 and installs the next callback; state 1 also sets the global flag.
extern "C" void DispatchModeFromSharedByteState(void) {
    switch (WfcUtility_GetBottomButtonSelection()) {
    case 0:
        WfcUtility_PlaySequenceArchiveEntry(7);
        break;
    case 1:
        WfcUtility_PlaySequenceArchiveEntry(6);
        *DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage = 1;
        break;
    default:
        return;
    }
    WfcUtility_SetMainLoopCallback(System_ResetSharedByteAndInstallMode8Callback);
}
