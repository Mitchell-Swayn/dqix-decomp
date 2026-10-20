#include <globaldefs.h>
ARM

extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned, unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned, unsigned);
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned, unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void Graphics_AdvanceSharedDisplayStateAndScheduleSetup(void);

// Original: arm9/ov031 @ 0x0222B5A0; symbol: func_ov031_0222b5a0; size: 0x70.
extern "C" void MainLoop_InitializeWhenContextReady(void) {
    if (WfcUtility_IsScreenTransitionBusy(1) != 0) {
        return;
    }
    if (WfcUtility_IsScreenTransitionBusy(0) != 0) {
        return;
    }
    Graphics_ClearIndexedMainBackgroundCharacterData(0);
    Overlay_ProcessPendingFlag();
    WfcUtility_DisableDisplayPlanes(1, 1);
    WfcUtility_DisableDisplayPlanes(0, 0x15);
    WfcUtility_SetNavigationContext(0, 0);
    WfcUtility_SetScreenOperationArguments(0, 1);
    WfcUtility_SetMainLoopCallback(Graphics_AdvanceSharedDisplayStateAndScheduleSetup);
}
