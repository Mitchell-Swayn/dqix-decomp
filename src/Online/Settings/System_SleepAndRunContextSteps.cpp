#include <globaldefs.h>
ARM
extern "C" void _Z19SleepCurrentContextj(unsigned ticks);
extern "C" void WfcMultiScreen_DispatchTaskResult(void);
extern "C" void WfcMultiScreen_RequestCancelFromInput(void);
extern "C" void WfcMultiScreen_ReturnFromPollingHook(void);
extern "C" void System_InstallCallbackIfSharedByteIsZero(void);
// Original: arm9/ov031 @ 0x02231284; symbol: func_ov031_02231284; size: 0x20.
extern "C" void System_SleepAndRunContextSteps(void) {
    _Z19SleepCurrentContextj(10);
    WfcMultiScreen_DispatchTaskResult();
    WfcMultiScreen_RequestCancelFromInput();
    WfcMultiScreen_ReturnFromPollingHook();
    System_InstallCallbackIfSharedByteIsZero();
}
