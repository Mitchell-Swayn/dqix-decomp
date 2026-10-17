#include <globaldefs.h>
ARM
extern "C" void _Z19SleepCurrentContextj(unsigned int ticks);
extern "C" void func_ov031_02231f54(void);
extern "C" void ClearPendingByteWhenConditionFalse(void);
extern "C" void func_ov031_02231dc8(void);
extern "C" void System_InitializeAndSetMainLoopCallbackIfSharedByteZero(void);
// Original: arm9/ov031 @ 0x02231D70; symbol: func_ov031_02231d70; size: 0x20.
extern "C" void System_Sleep10TicksAndRunAdjacentHelpers(void) {
    _Z19SleepCurrentContextj(10);
    func_ov031_02231f54();
    ClearPendingByteWhenConditionFalse();
    func_ov031_02231dc8();
    System_InitializeAndSetMainLoopCallbackIfSharedByteZero();
}
