#include <globaldefs.h>
ARM
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
extern "C" unsigned WfcUtility_DisableDisplayPlanes(...);
extern "C" unsigned Graphics_ClearIndexedMainBackgroundCharacterData(...);
extern "C" unsigned WfcUtility_IsBottomButtonBarAbsentOrNotClosing(...);
extern "C" unsigned System_ValidateThenFreeSharedGlobalAllocation(...);
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(...);
extern "C" unsigned WfcUtility_SetMainLoopCallback(...);
extern "C" unsigned WfcUtility_SetNavigationContext(...);
extern "C" unsigned Overlay_ProcessPendingFlag(...);
extern "C" unsigned WfcUtility_DestroyAnimatedStatusSprite(...);
// Original data: arm9/ov031 @ 0x2290cb0; symbol: data_ov031_02290cb0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage[];
extern "C" void WfcConnectionMethod_InitializeChooser();
extern "C" void Ov031_InitializeTransitionSequence();
// Original: arm9/ov031 @ 0x022317A8; symbol: FinishIdleTransitionAndChooseNextCallback; size: 0xbc.
// Waits for idle contexts, clears transition resources and selects next callback from global mode.
extern "C" void WfcUtility_FinishValidatedScreenTransition(){
 if(WfcUtility_IsScreenTransitionBusy(0))return;if(!B(DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage,0)&&WfcUtility_IsScreenTransitionBusy(1))return;if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;
 WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);if(!B(DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage,0)){Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);}
 System_ValidateThenFreeSharedGlobalAllocation();if(!B(DispatchOverlayStateTransition_UnknownRoleZeroInitializedStorage,0)){WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(WfcConnectionMethod_InitializeChooser);}else{WfcUtility_SetNavigationContext(0,0);WfcUtility_SetMainLoopCallback(Ov031_InitializeTransitionSequence);}
}
