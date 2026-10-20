#include <globaldefs.h>
ARM
extern "C" void WfcUtility_QueueConnectionErrorAcknowledgement(void);
extern "C" void WfcUtility_RunEmptyConnectionErrorUpdateHook(void);
extern "C" void WfcUtility_DispatchConnectionErrorAcknowledgement(void);
// Original: arm9/ov031 @ 0x0222E890; symbol: Overlay_ApplyPendingInputAndSelectCallbackForSharedByte; size: 0x14.
// Applies the pending-byte update for the held input mask, then selects a callback when the shared byte is zero.
extern "C" void WfcUtility_UpdateConnectionErrorInput(void) {
    WfcUtility_QueueConnectionErrorAcknowledgement();
    WfcUtility_RunEmptyConnectionErrorUpdateHook();
    WfcUtility_DispatchConnectionErrorAcknowledgement();
}
