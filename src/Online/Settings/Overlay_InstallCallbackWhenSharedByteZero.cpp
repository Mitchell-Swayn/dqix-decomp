#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetDialogSelectionResult(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(int);
extern "C" void CreateSharedDisplayResource(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallFallbackCallbackIfNoSharedObject(void);
// Original: arm9/ov031 @ 0x0222B388; symbol: func_ov031_0222b388; size: 0x2C.
extern "C" void Overlay_InstallCallbackWhenSharedByteZero(void) {
    if (WfcUtility_GetDialogSelectionResult() != 0)
        return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    CreateSharedDisplayResource();
    WfcUtility_SetMainLoopCallback(System_InstallFallbackCallbackIfNoSharedObject);
}
