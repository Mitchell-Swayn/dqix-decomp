#include <globaldefs.h>
ARM

extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_CreateSlidingDialog(unsigned, unsigned, unsigned, int, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void RegisterCallbackWhenSharedObjectAbsent(void);

// Original: arm9/ov031 @ 0x02231008; symbol: func_ov031_02231008; size: 0x50.
extern "C" void System_InitializeActionWhenBothContextsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) {
        return;
    }
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) {
        return;
    }
    WfcUtility_CreateSlidingDialog(0x44, 5, 1, -1, 0);
    WfcUtility_SetMainLoopCallback(RegisterCallbackWhenSharedObjectAbsent);
}
