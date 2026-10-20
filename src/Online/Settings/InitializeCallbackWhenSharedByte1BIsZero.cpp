#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int value);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void System_InstallMode8CallbackWhenObjectAbsent(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02231FD8; symbol: func_ov031_02231fd8; size: 0x2C.
extern "C" void InitializeCallbackWhenSharedByte1BIsZero(void) {
    if (WfcUtility_GetDialogSelectionResult() != 0) return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_InstallMode8CallbackWhenObjectAbsent);
}
