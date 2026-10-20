#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void WfcUtility_ArmAccessPointListInput(void);
// Original: arm9/ov031 @ 0x0222CB8C; symbol: System_EnterModeSixAndInstallSharedObjectFallbackCallback; size: 0x2C.
// When the shared-object byte is zero, selects mode 6, creates the shared display resource, and installs the callback that handles the no-shared-object path.
extern "C" void System_EnterModeSixAndInstallSharedObjectFallbackCallback(void) {
    if (WfcUtility_GetDialogSelectionResult() == 0) {
        WfcUtility_PlaySequenceArchiveEntry(6);
        CreateSharedDisplayResource();
        WfcUtility_SetMainLoopCallback(WfcUtility_ArmAccessPointListInput);
    }
}
