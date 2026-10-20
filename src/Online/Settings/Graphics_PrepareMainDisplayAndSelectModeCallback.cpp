#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsConnectionContextAbsent();
extern "C" void WfcUtility_DestroyWirelessRegionIndicator();
extern "C" void WfcUtility_DestroyAnimatedStatusSprite();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
// Original data: arm9/ov031 @ 0x2290c68; symbol: data_ov031_02290c68.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_InitializeResponsePrompt();
extern "C" void System_LoadMainBG2AndScheduleMode0x21Callback();
extern "C" void Graphics_SubmitConfiguredBuffer31AndRegisterDisplayCallback();
// Original: arm9/ov031 @ 0x022298D0; symbol: Graphics_PrepareMainDisplayAndSelectModeCallback; size: 0x94.
// Prepares idle main display then selects callback for mode byte zero, two or other.
extern "C" void Graphics_PrepareMainDisplayAndSelectModeCallback() {
 if(WfcUtility_IsScreenTransitionBusy(0))return;if(!WfcUtility_IsConnectionContextAbsent())return;
 WfcUtility_DestroyWirelessRegionIndicator();WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);WfcUtility_DisableDisplayPlanes(0,0x15);WfcUtility_SetNavigationContext(0,1);
 if(WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage==0)WfcUtility_SetMainLoopCallback(WfcUtility_InitializeResponsePrompt);else if(WfcUtilityHandleMultiNoticeResult_UnknownRoleZeroInitializedStorage==2)WfcUtility_SetMainLoopCallback(System_LoadMainBG2AndScheduleMode0x21Callback);else WfcUtility_SetMainLoopCallback(Graphics_SubmitConfiguredBuffer31AndRegisterDisplayCallback);
}
