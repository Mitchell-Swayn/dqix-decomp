#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsModeSpriteExitInactive();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcSettingsList_InitializeScreen();
extern "C" void WfcUtility_InitializeMainMenu();
// Original: arm9/ov031 @ 0x02233FAC; symbol: func_ov031_02233fac; size: 0xA4.
extern "C" void Graphics_TransitionDisplayAndSelectStoredWordCallback() {
 if(WfcUtility_IsScreenTransitionBusy(1)) return;
 if(WfcUtility_IsScreenTransitionBusy(0)) return;
 if(!WfcUtility_IsModeSpriteExitInactive()) return;
 Graphics_ClearIndexedMainBackgroundCharacterData(0);
 Overlay_ProcessPendingFlag();
 WfcUtility_DisableDisplayPlanes(1,1);
 WfcUtility_DisableDisplayPlanes(0,0x15);
 WfcUtility_SetNavigationContext(2,1);
 unsigned word;
 WfcUtility_GetScreenOperationArguments(0,&word);
 if(!word) {
  WfcUtility_SetScreenOperationArguments(0,0);
  WfcUtility_SetMainLoopCallback(WfcSettingsList_InitializeScreen);
 } else WfcUtility_SetMainLoopCallback(WfcUtility_InitializeMainMenu);
}
