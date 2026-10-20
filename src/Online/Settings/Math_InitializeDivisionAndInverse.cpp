#include <globaldefs.h>
ARM
extern "C" void WfcUtility_RunMultiNoticeInputHook(void);
extern "C" void WfcUtility_RunMultiNoticeUpdateHook(void);
// Original: arm9/ov031 @ 0x02229890; symbol: func_ov031_02229890; size: 0x10.
extern "C" void Math_InitializeDivisionAndInverse(void) {
    WfcUtility_RunMultiNoticeInputHook();
    WfcUtility_RunMultiNoticeUpdateHook();
}
