#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" unsigned int WfcUtility_GetInitialMenuSelector(void);
extern "C" void WfcUtility_SetNavigationContext(unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void*);
extern "C" void WfcUtility_InitializeMainMenu(void);
extern "C" void Ov031_InitializeSecondaryTransition(void);
// Original: arm9/ov031 @ 0x02227FB0; symbol: func_ov031_02227fb0; size: 0x74.
extern "C" void WfcUtility_SelectInitialMenuAfterFade(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    unsigned state = WfcUtility_GetInitialMenuSelector();
    switch (state) {
    case 0:
        WfcUtility_SetNavigationContext(0, 1);
        WfcUtility_SetMainLoopCallback((void*)WfcUtility_InitializeMainMenu);
        break;
    case 1:
        WfcUtility_SetNavigationContext(1, 1);
        WfcUtility_SetMainLoopCallback((void*)Ov031_InitializeSecondaryTransition);
        break;
    default:
        break;
    }
}
