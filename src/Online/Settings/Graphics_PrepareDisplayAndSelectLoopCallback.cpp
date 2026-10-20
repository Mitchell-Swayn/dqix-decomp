#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c6c; symbol: data_ov031_02290c6c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" {extern unsigned char DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage;int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();void Overlay_ProcessPendingFlag();void WfcUtility_SetMainLoopCallback(void(*)());void WfcUtility_SetNavigationContext(unsigned,unsigned);unsigned WfcUtility_IsScreenTransitionBusy(int);void Graphics_ClearIndexedMainBackgroundCharacterData(int);void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);void Graphics_InitializeMappedPaletteScreenAndCallback();void Overlay_InitializeAndInstallCallback();}
// Original: arm9/ov031 @ 0x0222A0BC; symbol: func_ov031_0222a0bc; size: 0xB8.
extern "C" void Graphics_PrepareDisplayAndSelectLoopCallback(){
if(WfcUtility_IsScreenTransitionBusy(0))return;
if(!DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage){if(WfcUtility_IsScreenTransitionBusy(1))return;}
if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;
Graphics_ClearIndexedMainBackgroundCharacterData(0);
if(!DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage){Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);}
WfcUtility_DisableDisplayPlanes(0,0x15);
if(!DispatchModeFromSharedByteState_UnknownRoleZeroInitializedStorage){WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback);}
else{WfcUtility_SetNavigationContext(0,1);WfcUtility_SetMainLoopCallback(Overlay_InitializeAndInstallCallback);}
}
