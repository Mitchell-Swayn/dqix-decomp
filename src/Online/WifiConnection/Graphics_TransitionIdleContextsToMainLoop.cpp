#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290ce0; symbol: data_ov031_02290ce0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" { int WfcUtility_IsBottomButtonBarAbsentOrNotClosing(); void Overlay_ProcessPendingFlag(); void WfcUtility_SetMainLoopCallback(void(*)()); void WfcUtility_SetNavigationContext(unsigned,unsigned); unsigned WfcUtility_IsScreenTransitionBusy(int); void Graphics_ClearIndexedMainBackgroundCharacterData(int); void WfcUtility_DisableDisplayPlanes(unsigned,unsigned); void Ov031_InitializeSecondaryTransition(); void System_CopyHardwareConfigurationAndInstallMenuCallbacks(); extern unsigned char OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage; }
// Original: arm9/ov031 @ 0x022347F4; symbol: func_ov031_022347f4; size: 0xB8.
extern "C" void Graphics_TransitionIdleContextsToMainLoop() {
 if(WfcUtility_IsScreenTransitionBusy(0)) return;
 if(!OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage && WfcUtility_IsScreenTransitionBusy(1)) return;
 if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing()) return;
 Graphics_ClearIndexedMainBackgroundCharacterData(0);
 if(!OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage) { Overlay_ProcessPendingFlag(); WfcUtility_DisableDisplayPlanes(1,1); }
 WfcUtility_DisableDisplayPlanes(0,21);
 if(!OverlaySelectCallbackFromSharedByte_UnknownRoleZeroInitializedStorage) { WfcUtility_SetNavigationContext(2,1); WfcUtility_SetMainLoopCallback(Ov031_InitializeSecondaryTransition); }
 else { WfcUtility_SetNavigationContext(2,1); WfcUtility_SetMainLoopCallback(System_CopyHardwareConfigurationAndInstallMenuCallbacks); }
}
