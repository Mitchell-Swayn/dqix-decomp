#include <globaldefs.h>
ARM
extern "C" void Ov031_AdvanceCallbackDelay(void);
extern "C" void WfcUtility_RunEmptyTimedNoticeUpdateHook(void);

// Original: arm9/ov031 @ 0x0222B550; symbol: func_ov031_0222b550; size: 0x10.
extern "C" void WfcUtility_UpdateTimedNoticeWait(void) {
    Ov031_AdvanceCallbackDelay();
    WfcUtility_RunEmptyTimedNoticeUpdateHook();
}
