#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void OS_SpinWait(register unsigned int cycles);
extern "C" void DrainPendingCommandsResetDMAAndHalt(void);
// Original: arm9/ov031 @ 0x02229BC8; symbol: func_ov031_02229bc8; size: 0x34.
extern "C" void WfcUtility_HaltAfterMultiNoticeCompletionFade(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    OS_SpinWait(0x01000000);
    DrainPendingCommandsResetDMAAndHalt();
}
