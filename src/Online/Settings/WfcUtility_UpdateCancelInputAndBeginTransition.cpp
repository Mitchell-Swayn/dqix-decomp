#include <globaldefs.h>
ARM
extern "C" void WfcUtility_QueueCancelOnBOrHardwareFlag(void);
extern "C" void WfcUtility_RunEmptyCancelInputHook(void);
extern "C" void System_InitializeCallbackAfterSharedByteChecks(void);
// Original: arm9/ov031 @ 0x02234A90; symbol: System_SetPendingInputAndInitializeCallback; size: 0x14.
// Sets pending input from the held mask or validated event, then initializes the callback after shared-byte checks.
extern "C" void WfcUtility_UpdateCancelInputAndBeginTransition(void) {
    WfcUtility_QueueCancelOnBOrHardwareFlag();
    WfcUtility_RunEmptyCancelInputHook();
    System_InitializeCallbackAfterSharedByteChecks();
}
