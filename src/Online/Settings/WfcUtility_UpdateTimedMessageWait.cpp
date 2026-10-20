#include <globaldefs.h>
ARM
extern "C" void WfcUtility_AdvanceTimedMessageCounter(void);
extern "C" void WfcUtility_RunEmptyTimedMessageUpdateHook(void);
// Original: arm9/ov031 @ 0x0222A274; symbol: func_ov031_0222a274; size: 0x10.
extern "C" void WfcUtility_UpdateTimedMessageWait(void) {
    WfcUtility_AdvanceTimedMessageCounter();
    WfcUtility_RunEmptyTimedMessageUpdateHook();
}
