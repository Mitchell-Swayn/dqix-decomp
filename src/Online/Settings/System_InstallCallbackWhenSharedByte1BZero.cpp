#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallConditionalLayerCallbackWhenObjectAbsent(void);
// Original: arm9/ov031 @ 0x0223193C; symbol: func_ov031_0223193c; size: 0x2C.
extern "C" void System_InstallCallbackWhenSharedByte1BZero(void) {
    if (WfcUtility_GetDialogSelectionResult() != 0)
        return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_InstallConditionalLayerCallbackWhenObjectAbsent);
}
