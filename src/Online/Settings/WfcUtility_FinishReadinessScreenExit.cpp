#include <globaldefs.h>
ARM
extern "C" void WfcConnectionMethod_InitializeChooser();extern "C" void InitializeOverlayProgressScreen();
extern "C" int WfcUtility_DisableDisplayPlanes(...);
extern "C" int WfcUtility_GetEditableConnectionProfile(...);
extern "C" int Graphics_ClearIndexedMainBackgroundCharacterData(...);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing(...);
extern "C" int Network_SubmitWirelessOperationsAndWaitForStateTwo(...);
extern "C" int Overlay_ProcessPendingFlag(...);
extern "C" int WfcUtility_IsScreenTransitionBusy(...);
extern "C" int WfcUtility_SetMainLoopCallback(...);
extern "C" int WfcUtility_SetScreenOperationArguments(...);
extern "C" int WfcUtility_SetNavigationContext(...);
extern "C" int WfcUtility_DestroyAnimatedStatusSprite(...);
extern "C" int Overlay_ProcessPendingFlag(...);
extern "C" int WfcUtility_FreeWirelessScanBufferWhenInactive(...);
extern "C" int Network_SubmitWirelessOperationsAndWaitForStateTwo(...);
extern "C" int WfcUtility_SelectConnectionProfileForEditing(...);
extern "C" int Graphics_ClearIndexedMainBackgroundCharacterData(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);
// Original data: arm9/ov031 @ 0x2290cbc; symbol: data_ov031_02290cbc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage[];

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
// Original: arm9/ov031 @ 0x022323F0; symbol: WaitForIdleDisplaysAndInstallSelectedMainLoop.
extern "C" void WfcUtility_FinishReadinessScreenExit(void){
if(WfcUtility_IsScreenTransitionBusy(1))return;if(WfcUtility_IsScreenTransitionBusy(0))return;if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;while(!Network_SubmitWirelessOperationsAndWaitForStateTwo()){}WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);WfcUtility_DisableDisplayPlanes(0,21);if(B(WfcUtilityFinishReadinessScreenExit_UnknownRoleZeroInitializedStorage,0)!=1){WfcUtility_FreeWirelessScanBufferWhenInactive();WfcUtility_SelectConnectionProfileForEditing(B(C(WfcUtility_GetEditableConnectionProfile()),244));WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(WfcConnectionMethod_InitializeChooser);}else{WfcUtility_SetNavigationContext(0,1);WfcUtility_SetScreenOperationArguments(0,0);WfcUtility_SetMainLoopCallback(InitializeOverlayProgressScreen);}
}
