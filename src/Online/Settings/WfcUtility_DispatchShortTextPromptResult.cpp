#include <globaldefs.h>
ARM
extern "C" void WfcUtility_RunEmptyTextResultPrelude(void);
extern "C" void WfcUtility_RunEmptyTextResultFollowup(void);
extern "C" int WfcUtility_GetDialogSelectionResult(void);
// Original data: arm9/ov031 @ 0x2290c78; symbol: data_ov031_02290c78.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void WfcUtility_SetConnectionEventCallback(unsigned);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void ConfigureThirdContextFromSharedState(void);
// Original: arm9/ov031 @ 0x0222A890; symbol: func_ov031_0222a890; size: 0x70.
extern "C" void WfcUtility_DispatchShortTextPromptResult(void) {
    WfcUtility_RunEmptyTextResultPrelude();
    WfcUtility_RunEmptyTextResultFollowup();
    int state = WfcUtility_GetDialogSelectionResult();
    switch (state) {
    case 0:
        *((unsigned char*)&ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage + 1) = 0;
        WfcUtility_PlaySequenceArchiveEntry(7);
        break;
    case 1:
        *((unsigned char*)&ConfigureThirdContextFromSharedState_UnknownRoleZeroInitializedStorage + 1) = 1;
        WfcUtility_PlaySequenceArchiveEntry(0xe);
        break;
    default:
        return;
    }
    WfcUtility_SetConnectionEventCallback(0);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback((void*)ConfigureThirdContextFromSharedState);
}
