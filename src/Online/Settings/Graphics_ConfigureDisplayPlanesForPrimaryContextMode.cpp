#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c58; symbol: data_ov031_02290c58.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(int);
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void Graphics_InitializeMappedPaletteScreenAndCallback();
extern "C" void System_InitializeContextAndCallback();
// Original: arm9/ov031 @ 0x02228858; symbol: func_ov031_02228858; size: 0xB8.
extern "C" void Graphics_ConfigureDisplayPlanesForPrimaryContextMode() {
 if(WfcUtility_IsScreenTransitionBusy(0)) return;
 if(!WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage[0] && WfcUtility_IsScreenTransitionBusy(1)) return;
 if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing()) return;
 Graphics_ClearIndexedMainBackgroundCharacterData(0);
 if(!WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage[0]) { Overlay_ProcessPendingFlag(); WfcUtility_DisableDisplayPlanes(1,1); }
 WfcUtility_DisableDisplayPlanes(0,0x15);
 if(!WfcUtilityInitializeMultiScreen_UnknownRoleZeroInitializedStorage[0]) { WfcUtility_SetNavigationContext(0,1); WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback); }
 else { WfcUtility_SetNavigationContext(0,1); WfcUtility_SetMainLoopCallback(System_InitializeContextAndCallback); }
}
