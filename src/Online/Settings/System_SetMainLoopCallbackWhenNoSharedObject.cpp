#include <globaldefs.h>
ARM
extern "C" int WfcUtility_IsDialogActive(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void System_HandleInputAndAdvanceState(void);

// Original: arm9/ov031 @ 0x02230ED0; symbol: func_ov031_02230ed0; size: 0x20.
extern "C" void System_SetMainLoopCallbackWhenNoSharedObject(void) {
    if (WfcUtility_IsDialogActive())
        return;
    WfcUtility_SetMainLoopCallback(System_HandleInputAndAdvanceState);
}
