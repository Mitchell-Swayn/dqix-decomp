#include <globaldefs.h>
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(unsigned);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned, unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned, unsigned);
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned, unsigned);
extern "C" void Graphics_AdvanceSharedDisplayStateAndScheduleSetup();
extern "C" void WfcUtility_SetMainLoopCallback(void (*)());
// Original: arm9/ov031 @ 0x0223447C; symbol: func_ov031_0223447c; size: 0x70.
extern "C" ARM void Ov031_ConfigureDisplayAfterContextReady() {
    if (WfcUtility_IsScreenTransitionBusy(1)) return;
    if (WfcUtility_IsScreenTransitionBusy(0)) return;
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    Overlay_ProcessPendingFlag();
    WfcUtility_DisableDisplayPlanes(1, 1);
    WfcUtility_DisableDisplayPlanes(0, 0x15);
    WfcUtility_SetNavigationContext(0, 0);
    WfcUtility_SetScreenOperationArguments(0, 2);
    WfcUtility_SetMainLoopCallback(Graphics_AdvanceSharedDisplayStateAndScheduleSetup);
}
