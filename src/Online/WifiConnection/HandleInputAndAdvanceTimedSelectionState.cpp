#include <globaldefs.h>
ARM
extern "C" void System_HandleHeldInputMaskBit2(void);
extern "C" void WfcUtility_RunReadinessScreenNoOp(void);
extern "C" void System_EnterModeSevenAndInstallStandardLayerCallback(void);
extern "C" void WfcUtility_UpdateAccessPointReadiness(void);
// Original: arm9/ov031 @ 0x022321EC; symbol: HandleInputAndAdvanceTimedSelectionState; size: 0x18.
// Runs input handling, a shared-byte guarded selector/callback transition, then a timer-driven state handler.
extern "C" void HandleInputAndAdvanceTimedSelectionState(void) {
    System_HandleHeldInputMaskBit2();
    WfcUtility_RunReadinessScreenNoOp();
    System_EnterModeSevenAndInstallStandardLayerCallback();
    WfcUtility_UpdateAccessPointReadiness();
}
