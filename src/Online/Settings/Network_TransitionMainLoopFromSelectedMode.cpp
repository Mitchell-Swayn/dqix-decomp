#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(unsigned);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_SetScreenOperationArguments(unsigned,unsigned);
extern "C" void WfcSettingsList_SetEntryOriginMode(unsigned char);
extern "C" void Ov031_InitializeSecondaryTransition();
extern "C" void InitializeBG2Mode33AndInstallCallback();
extern "C" void InitializeSharedDisplayStateAndInstallCallback();
extern "C" void Ov031_InitializeMapTransition();
extern "C" void WfcSettingsList_InitializeScreen();
// Original data: arm9/ov031 @ 0x2290cc8; symbol: data_ov031_02290cc8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02233784; symbol: func_ov031_02233784; size: 0x130.
extern "C" void Network_TransitionMainLoopFromSelectedMode() {
 if(WfcUtility_IsScreenTransitionBusy(1))return;
 if(WfcUtility_IsScreenTransitionBusy(0))return;
 if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;
 Overlay_ClearFourSharedObjects();
 Overlay_ProcessPendingFlag();
 WfcUtility_FreeArchiveResourceAndReturnPoolEntry(*(unsigned*)(SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage+4));
 WfcUtility_DisableDisplayPlanes(1,1);
 WfcUtility_DisableDisplayPlanes(0,0x14);
 if(!*(unsigned char*)(SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage+2)) {
  WfcUtility_SetNavigationContext(2,0);
  WfcUtility_SetMainLoopCallback(Ov031_InitializeSecondaryTransition);
  return;
 }
 switch(*(signed char*)(SystemConfigureSecondaryDisplayMode_UnknownRoleZeroInitializedStorage+1)) {
 case 0:WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(InitializeBG2Mode33AndInstallCallback);break;
 case 1:WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(InitializeSharedDisplayStateAndInstallCallback);break;
 case 2:WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(Ov031_InitializeMapTransition);break;
 case 3:WfcUtility_SetNavigationContext(2,0);WfcUtility_SetScreenOperationArguments(0,0);WfcSettingsList_SetEntryOriginMode(1);WfcUtility_SetMainLoopCallback(WfcSettingsList_InitializeScreen);break;
 }
}
