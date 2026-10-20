#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void WfcUtility_RestoreProfileHeadersAndSelectNextScreen(void);
// Original: arm9/ov031 @ 0x02233CBC; symbol: func_ov031_02233cbc; size: 0x24.
extern "C" void System_InstallAlternateCallbackIfScreenZeroContextByteIsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) == 0)
        WfcUtility_SetMainLoopCallback(WfcUtility_RestoreProfileHeadersAndSelectNextScreen);
}
