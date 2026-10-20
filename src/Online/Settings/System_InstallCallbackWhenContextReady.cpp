#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing(void);
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int screen);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned engine, unsigned mask);
extern "C" void WfcUtility_SetNavigationContext(unsigned a, unsigned b);
extern "C" void System_InitializeMenuWithResetAndCallback(void);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
// Original: arm9/ov031 @ 0x02229DD8; symbol: func_ov031_02229dd8; size: 0x50.
extern "C" void System_InstallCallbackWhenContextReady(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0)
        return;
    if (!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())
        return;
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    WfcUtility_DisableDisplayPlanes(0, 0x15);
    WfcUtility_SetNavigationContext(0, 1);
    WfcUtility_SetMainLoopCallback(System_InitializeMenuWithResetAndCallback);
}
