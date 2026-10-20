#include <globaldefs.h>
ARM
extern "C" void WfcUtility_WaitForTimedScreenFadeOut(void);
extern "C" void WfcUtility_RunEmptyTimedScreenHook(void);

// Original: arm9/ov031 @ 0x0223442C; symbol: func_ov031_0223442c; size: 0x10.
extern "C" void WfcUtility_UpdateTimedScreenAndRunEmptyHook(void) {
    WfcUtility_WaitForTimedScreenFadeOut();
    WfcUtility_RunEmptyTimedScreenHook();
}
