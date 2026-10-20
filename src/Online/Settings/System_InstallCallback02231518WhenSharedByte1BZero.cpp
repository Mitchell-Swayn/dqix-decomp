#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void System_InstallAlternateSharedByteSetupCallbackWhenObjectAbsent(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
// Original: arm9/ov031 @ 0x022314EC; symbol: func_ov031_022314ec; size: 0x2C.
extern "C" void System_InstallCallback02231518WhenSharedByte1BZero(void) {
    if (WfcUtility_GetDialogSelectionResult() == 0) {
        WfcUtility_PlaySequenceArchiveEntry(6);
        CreateSharedDisplayResource();
        WfcUtility_SetMainLoopCallback(System_InstallAlternateSharedByteSetupCallbackWhenObjectAbsent);
    }
}
