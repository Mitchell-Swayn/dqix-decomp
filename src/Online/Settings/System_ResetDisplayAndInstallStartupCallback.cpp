#include <globaldefs.h>
ARM
extern "C" unsigned int WfcUtility_IsScreenTransitionBusy(int);
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void Overlay_ProcessPendingFlag(void);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned int, unsigned int);
extern "C" void WfcUtility_SetNavigationContext(unsigned int, unsigned int);
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned int, unsigned int);
extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void));
extern "C" void Graphics_AdvanceSharedDisplayStateAndScheduleSetup(void);
// Original: arm9/ov031 @ 0x02231AEC; symbol: System_ResetDisplayAndInstallStartupCallback; size: 0x70.
// When context bytes 1 and 0 are both clear, runs the transition helpers, clears display planes, resets shared words, sets the main-loop pair, and installs callback 0x022340c0.
extern "C" void System_ResetDisplayAndInstallStartupCallback(void) {
 if (WfcUtility_IsScreenTransitionBusy(1)) return;
 if (WfcUtility_IsScreenTransitionBusy(0)) return;
 Graphics_ClearIndexedMainBackgroundCharacterData(0);
 Overlay_ProcessPendingFlag();
 WfcUtility_DisableDisplayPlanes(1, 1);
 WfcUtility_DisableDisplayPlanes(0, 0x15);
 WfcUtility_SetNavigationContext(0, 0);
 WfcUtility_SetScreenOperationArguments(0, 1);
 WfcUtility_SetMainLoopCallback(Graphics_AdvanceSharedDisplayStateAndScheduleSetup);
}
