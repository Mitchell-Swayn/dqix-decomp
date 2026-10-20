#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection();
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
extern "C" void WfcUtility_QueueResponsePromptExit();
// Original data: arm9/ov031 @ 0x2290c74; symbol: data_ov031_02290c74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222A540; symbol: SetFlagAndDispatchModeFromSharedByte; size: 0x58.
// Maps shared byte 0 to mode 7 and flag 0, byte 1 to mode 6 and flag 1, then installs the callback.
extern "C" void SetFlagAndDispatchModeFromSharedByte(void) {
    int value = WfcUtility_GetBottomButtonSelection();
    if (value != 0) {
        if (value != 1) return;
        WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[1] = 1;
        WfcUtility_PlaySequenceArchiveEntry(6);
    } else {
        WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[1] = 0;
        WfcUtility_PlaySequenceArchiveEntry(7);
    }
    WfcUtility_SetMainLoopCallback(WfcUtility_QueueResponsePromptExit);
}
