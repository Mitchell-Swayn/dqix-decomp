#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_StopSequenceImmediately(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByteAndInstallMode8Callback(void);
// Original: arm9/ov031 @ 0x02231DCC; symbol: func_ov031_02231dcc; size: 0x2C.
extern "C" void System_InitializeAndSetMainLoopCallbackIfSharedByteZero(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_StopSequenceImmediately();
    WfcUtility_PlaySequenceArchiveEntry(7);
    WfcUtility_SetMainLoopCallback(System_SetSharedByteAndInstallMode8Callback);
}
