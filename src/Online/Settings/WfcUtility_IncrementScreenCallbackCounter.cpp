#include <globaldefs.h>
ARM
extern "C" void System_IncrementMainLoopCallbackCounter(void);
extern "C" void WfcUtility_ReturnFromCounterFollowupHook(void);
// Original: arm9/ov031 @ 0x02231A9C; symbol: func_ov031_02231a9c; size: 0x10.
extern "C" void WfcUtility_IncrementScreenCallbackCounter(void) { System_IncrementMainLoopCallbackCounter(); WfcUtility_ReturnFromCounterFollowupHook(); }
