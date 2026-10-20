#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void WfcUtility_CreateBottomButtonsForDisplayMode(int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_InstallFourthMainLoopCallbackUnlessSharedByteIsMinus2(void);
// Original: arm9/ov031 @ 0x02231230; symbol: func_ov031_02231230; size: 0x2C.
extern "C" void Overlay_InstallCallbackWhenContextByteZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    WfcUtility_CreateBottomButtonsForDisplayMode(1);
    WfcUtility_SetMainLoopCallback(System_InstallFourthMainLoopCallbackUnlessSharedByteIsMinus2);
}
