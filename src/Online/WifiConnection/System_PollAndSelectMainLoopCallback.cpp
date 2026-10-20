#include <globaldefs.h>
ARM
extern "C" void WfcUtility_WaitForScreenDelayAndSelectExit(void);
extern "C" void WfcUtility_RunEmptyDelayedScreenHook(void);
// Original: arm9/ov031 @ 0x02233F40; symbol: System_PollAndSelectMainLoopCallback; size: 0x10.
// Polls and selects the main-loop callback, then invokes an empty routine.
extern "C" void System_PollAndSelectMainLoopCallback(void) {
    WfcUtility_WaitForScreenDelayAndSelectExit();
    WfcUtility_RunEmptyDelayedScreenHook();
}
