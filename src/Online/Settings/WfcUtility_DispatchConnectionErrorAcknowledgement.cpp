#include <globaldefs.h>
ARM
extern "C" int WfcUtility_GetBottomButtonSelection(void);
extern "C" void WfcUtility_PlaySequenceArchiveEntry(unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedContextAndInstallSecondCallback(void);
// Original: arm9/ov031 @ 0x0222E8C8; symbol: Unclassified_ResolveGroup6AndInstallCallbackWhenSharedByteZero_0222E8C8; size: 0x28.
// When the shared signed byte is zero, resolves group 6 and installs the next main-loop callback. The same behavior description applies to another handler in this overlay; temporary address suffix, naming refinement pending callback-sequence comparison.
extern "C" void WfcUtility_DispatchConnectionErrorAcknowledgement(void) {
    if (WfcUtility_GetBottomButtonSelection() == 0) {
        WfcUtility_PlaySequenceArchiveEntry(6);
        WfcUtility_SetMainLoopCallback(System_SetSharedContextAndInstallSecondCallback);
    }
}
