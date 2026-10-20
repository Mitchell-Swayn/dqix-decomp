#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" int WfcUtility_PlaySequenceArchiveEntry(int mode);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void System_SetAlternateMainLoopCallbackWhenNoSharedObject(void);
// Original: arm9/ov031 @ 0x02234D98; symbol: func_ov031_02234d98; size: 0x2C.
extern "C" void System_InstallSecondModeCallbackWhenStateIsZero(void) {
    if (WfcUtility_GetDialogSelectionResult() != 0) return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_SetAlternateMainLoopCallbackWhenNoSharedObject);
}
