#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned);
extern "C" void System_SetSharedByte18AndRegisterSecondContextDisplayCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02229D54; symbol: Unclassified_ResolveGroup6AndInstallCallbackWhenSharedByteZero; size: 0x28.
// When the shared signed byte is zero, resolves group 6 and installs its next main-loop callback; caller evidence associates this handler with the input-mask-1 path.
extern "C" void WfcUtility_AcceptMultiReturnNotice(void) {
    if (WfcUtility_GetBottomButtonSelection() != 0)
        return;
    WfcUtility_PlaySequenceArchiveEntry(6);
    WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterSecondContextDisplayCallback);
}
