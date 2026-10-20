#include <globaldefs.h>
extern "C" int WfcUtility_GetDialogSelectionResult();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* volatile WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
extern "C" void System_DispatchSelectedSharedCallback();
// Original: arm9/ov031 @ 0x0222D418; symbol: func_ov031_0222d418; size: 0x5C.
extern "C" void System_DispatchSharedByteStateAndInstallCallback() {
    WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage[0x2a] = (unsigned char)WfcUtility_GetDialogSelectionResult();
    unsigned char state = WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage[0x2a];
    switch (state) {
    case 0: WfcUtility_PlaySequenceArchiveEntry(7); break;
    case 1: WfcUtility_PlaySequenceArchiveEntry(0xe); break;
    default: return;
    }
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_DispatchSelectedSharedCallback);
}
