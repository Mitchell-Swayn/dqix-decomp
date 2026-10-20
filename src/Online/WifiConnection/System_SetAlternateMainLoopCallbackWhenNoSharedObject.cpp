#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_SetSharedByte18AndRegisterTransitionCallback(void);

// Original: arm9/ov031 @ 0x02234DC4; symbol: func_ov031_02234dc4; size: 0x20.
extern "C" void System_SetAlternateMainLoopCallbackWhenNoSharedObject(void) {
    if (WfcUtility_IsDialogActive())
        return;
    WfcUtility_SetMainLoopCallback(System_SetSharedByte18AndRegisterTransitionCallback);
}
