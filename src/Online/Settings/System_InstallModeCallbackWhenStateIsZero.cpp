#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(int mode);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void WfcUtility_ResumeWirelessTextEditorAfterPrompt(void);
// Original: arm9/ov031 @ 0x0222D6B0; symbol: func_ov031_0222d6b0; size: 0x2C.
extern "C" void System_InstallModeCallbackWhenStateIsZero(void) {
    if (WfcUtility_GetDialogSelectionResult() != 0) return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(WfcUtility_ResumeWirelessTextEditorAfterPrompt);
}
