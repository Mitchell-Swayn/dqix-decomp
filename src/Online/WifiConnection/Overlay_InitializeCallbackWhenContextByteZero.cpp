#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned, unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void InitializeBG2SharedSelectionAndCallback(void);
// Original: arm9/ov031 @ 0x022342D8; symbol: func_ov031_022342d8; size: 0x3C.
extern "C" void Overlay_InitializeCallbackWhenContextByteZero(void) {
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) return;
    WfcUtility_DisableDisplayPlanes(0, 0x14);
    WfcUtility_SetNavigationContext(0, 1);
    WfcUtility_SetMainLoopCallback(InitializeBG2SharedSelectionAndCallback);
}
