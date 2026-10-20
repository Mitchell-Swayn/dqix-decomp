#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c74; symbol: data_ov031_02290c74.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void Graphics_InitializeMappedPaletteScreenAndCallback();
extern "C" void System_InitializeMenuWithResetAndCallback();
// Original: arm9/ov031 @ 0x0222A61C; symbol: func_ov031_0222a61c; size: 0xA8.
extern "C" void Graphics_ConfigureDisplayPlanesAndSelectLoopCallback() {
 if(WfcUtility_IsScreenTransitionBusy(1)) return;
 if(WfcUtility_IsScreenTransitionBusy(0)) return;
 if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing()) return;
 Graphics_ClearIndexedMainBackgroundCharacterData(0);
 if(!WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[1]) { Overlay_ProcessPendingFlag(); WfcUtility_DisableDisplayPlanes(1,1); }
 WfcUtility_DisableDisplayPlanes(0,0x15);
 if(!WfcUtilityInitializeResponsePrompt_UnknownRoleZeroInitializedStorage[1]) { WfcUtility_SetNavigationContext(0,1); WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback); }
 else { WfcUtility_SetNavigationContext(0,1); WfcUtility_SetMainLoopCallback(System_InitializeMenuWithResetAndCallback); }
}
