#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int value);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned int engine, unsigned int mask);
extern "C" void WfcUtility_SetNavigationContext(unsigned int a, unsigned int b);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)(void));
extern "C" void Graphics_InitializeMappedPaletteScreenAndCallback(void);
// Original: arm9/ov031 @ 0x0222A2C4; symbol: func_ov031_0222a2c4; size: 0x64.
extern "C" void Overlay_InitializeCallbackAfterContextChecks(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0 || WfcUtility_IsScreenTransitionBusy(0) != 0) {
        return;
    }
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    Overlay_ProcessPendingFlag();
    WfcUtility_DisableDisplayPlanes(1, 1);
    WfcUtility_DisableDisplayPlanes(0, 0x15);
    WfcUtility_SetNavigationContext(0, 1);
    WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback);
}
