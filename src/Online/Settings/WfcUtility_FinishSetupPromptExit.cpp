#include <globaldefs.h>
ARM
#include <std_library_functions.h>
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
struct HighTwoBits{unsigned char low:6,high:2;};
extern "C" unsigned WfcUtility_DisableDisplayPlanes(...);
extern "C" unsigned Graphics_ClearIndexedMainBackgroundCharacterData(...);
extern "C" unsigned WfcUtility_IsBottomButtonBarAbsentOrNotClosing(...);
extern "C" unsigned Overlay_ProcessPendingFlag(...);
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(...);
extern "C" unsigned WfcUtility_SetMainLoopCallback(...);
extern "C" unsigned WfcUtility_SetNavigationContext(...);
extern "C" unsigned System_ReleaseSharedObjectIfInactive(...);
extern "C" unsigned WfcUtility_DestroyAnimatedStatusSprite(...);
extern "C" unsigned InitializeBG2StateAndInstallCallback(...);
extern "C" unsigned WfcConnectionMethod_InitializeChooser(...);
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0222b290; symbol: ResetDisplayPlanesAndInstallModeCallback.
extern "C" void WfcUtility_FinishSetupPromptExit(){if(WfcUtility_IsScreenTransitionBusy(0))return;if(!B(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage,0)){if(WfcUtility_IsScreenTransitionBusy(1))return;}if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;System_ReleaseSharedObjectIfInactive(B(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage,0)!=0);WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);if(!B(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage,0)){Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);}WfcUtility_DisableDisplayPlanes(0,21);if(!B(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage,0)){WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(WfcConnectionMethod_InitializeChooser);}else{WfcUtility_SetNavigationContext(0,0);WfcUtility_SetMainLoopCallback(InitializeBG2StateAndInstallCallback);}}
