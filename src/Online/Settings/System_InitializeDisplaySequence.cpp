#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int screen);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned engine, unsigned mask);
extern "C" void WfcUtility_SetNavigationContext(unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*callback)());
extern "C" void Graphics_InitializeMappedPaletteScreenAndCallback();
// Original: arm9/ov031 @ 0x02228FEC; symbol: func_ov031_02228fec; size: 0x70.
extern "C" void System_InitializeDisplaySequence(void) {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    if (!WfcUtility_IsBottomButtonBarAbsentOrNotClosing()) return;
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    Overlay_ProcessPendingFlag();
    WfcUtility_DisableDisplayPlanes(1, 1);
    WfcUtility_DisableDisplayPlanes(0, 0x15);
    WfcUtility_SetNavigationContext(0, 1);
    WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback);
}
