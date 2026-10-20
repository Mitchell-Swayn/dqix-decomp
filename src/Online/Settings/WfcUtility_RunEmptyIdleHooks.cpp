#include <globaldefs.h>
ARM
extern "C" void WfcUtility_RunEmptyIdlePreludeHook(void);
extern "C" void WfcUtility_RunEmptyIdleMiddleHook(void);
extern "C" void WfcUtility_RunEmptyIdleEpilogueHook(void);
// Original: arm9/ov031 @ 0x02233C74; symbol: func_ov031_02233c74; size: 0x14.
extern "C" void WfcUtility_RunEmptyIdleHooks(void) { WfcUtility_RunEmptyIdlePreludeHook(); WfcUtility_RunEmptyIdleMiddleHook(); WfcUtility_RunEmptyIdleEpilogueHook(); }
