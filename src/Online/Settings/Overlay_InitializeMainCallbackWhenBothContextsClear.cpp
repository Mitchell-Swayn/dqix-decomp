#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned, unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void Ov031_InitializeSecondaryTransition(void);
// Original: arm9/ov031 @ 0x022310C4; symbol: func_ov031_022310c4; size: 0x5C.
extern "C" void Overlay_InitializeMainCallbackWhenBothContextsClear(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) return;
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    Overlay_ProcessPendingFlag();
    WfcUtility_DisableDisplayPlanes(1, 1);
    WfcUtility_DisableDisplayPlanes(0, 0x14);
    WfcUtility_SetNavigationContext(2, 1);
    WfcUtility_SetMainLoopCallback(Ov031_InitializeSecondaryTransition);
}
