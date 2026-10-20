#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void System_ConfigureSharedByteAndAlternateCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void *callback);
// Original: arm9/ov031 @ 0x022312E0; symbol: func_ov031_022312e0; size: 0x2C.
extern "C" void System_InstallCallbackIfSharedByteIsZero(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback((void *)System_ConfigureSharedByteAndAlternateCallback);
}
