#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void Overlay_ClearSharedFlagAndSetCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x0222E378; symbol: func_ov031_0222e378; size: 0x2C.
extern "C" void System_InstallCallbackWhenSharedByte1BIsZero(void) {
    if (WfcUtility_GetDialogSelectionResult() != 0)
        return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback((void *)Overlay_ClearSharedFlagAndSetCallback);
}
