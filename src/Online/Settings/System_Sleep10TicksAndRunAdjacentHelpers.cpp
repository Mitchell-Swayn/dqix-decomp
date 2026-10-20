#include <globaldefs.h>
ARM
extern "C" void _Z19SleepCurrentContextj(unsigned int ticks);
extern "C" void WfcStepThreeScreen_DispatchTaskResult(void);
extern "C" void ClearPendingByteWhenConditionFalse(void);
extern "C" void WfcStepThreeScreen_ReturnFromPollingHook(void);
extern "C" void System_InitializeAndSetMainLoopCallbackIfSharedByteZero(void);
// Original: arm9/ov031 @ 0x02231D70; symbol: func_ov031_02231d70; size: 0x20.
extern "C" void System_Sleep10TicksAndRunAdjacentHelpers(void) {
    _Z19SleepCurrentContextj(10);
    WfcStepThreeScreen_DispatchTaskResult();
    ClearPendingByteWhenConditionFalse();
    WfcStepThreeScreen_ReturnFromPollingHook();
    System_InitializeAndSetMainLoopCallbackIfSharedByteZero();
}
