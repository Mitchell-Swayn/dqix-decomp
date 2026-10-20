#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void Overlay_ClearFourSharedObjects();
extern "C" void Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_FreeArchiveResourceAndReturnPoolEntry(void*);
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void Ov031_InitializeSecondaryTransition();
extern "C" void Graphics_InitializeMappedPaletteScreenAndCallback();
// Original data: arm9/ov031 @ 0x2290c50; symbol: data_ov031_02290c50.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02228444; symbol: func_ov031_02228444; size: 0xA8.
extern "C" void Graphics_FinishDisplayTransitionAndSelectCallback() {
if(WfcUtility_IsScreenTransitionBusy(1)) return;
if(WfcUtility_IsScreenTransitionBusy(0)) return;
Overlay_ClearFourSharedObjects();
Overlay_ProcessPendingFlag();
WfcUtility_FreeArchiveResourceAndReturnPoolEntry(*(void**)(WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage+4));
WfcUtility_DisableDisplayPlanes(1,1);
WfcUtility_DisableDisplayPlanes(0,20);
switch(*(unsigned char*)WfcUtilityInitializeMainMenu_UnknownRoleZeroInitializedStorage) {
case 0:WfcUtility_SetNavigationContext(1,0);WfcUtility_SetMainLoopCallback(Ov031_InitializeSecondaryTransition);break;
case 1:WfcUtility_SetNavigationContext(0,0);WfcUtility_SetMainLoopCallback(Graphics_InitializeMappedPaletteScreenAndCallback);break;
}
}
