#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_ResumeReadinessScreenAfterDialog(void);
// Original: arm9/ov031 @ 0x022324BC; symbol: System_EnterModeSixAndInstallCallbackWhenSharedObjectAbsent; size: 0x2C.
// When the shared-object byte is zero, selects mode 6, creates the shared display resource, and installs the callback that continues when the shared object is absent.
extern "C" void System_EnterModeSixAndInstallCallbackWhenSharedObjectAbsent(void) {
    if (WfcUtility_GetDialogSelectionResult() == 0) {
        WfcUtility_PlaySequenceArchiveEntry(6);
        CreateSharedDisplayResource();
        WfcUtility_SetMainLoopCallback(WfcUtility_ResumeReadinessScreenAfterDialog);
    }
}
