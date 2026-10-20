#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cac; symbol: data_ov031_02290cac.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[];
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" int WfcUtility_IsBottomButtonBarAbsentOrNotClosing();
extern "C" void System_ValidateThenFreeSharedGlobalAllocation();
extern "C" void Graphics_ClearIndexedMainBackgroundCharacterData(unsigned);
extern "C" int Overlay_ProcessPendingFlag();
extern "C" void WfcUtility_DisableDisplayPlanes(unsigned,unsigned);
extern "C" void WfcUtility_SetNavigationContext(unsigned,unsigned);
extern "C" void System_ValidateThenFreeSharedGlobalAllocation();
extern "C" void WfcUtility_DestroyAnimatedStatusSprite();
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcConnectionMethod_InitializeChooser(),System_InitializeMode2AAndScheduleCallback();
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
// Original: arm9/ov031 @ 0x022313A0; symbol: System_AdvanceScreenAfterContextReadiness; size: 0xc8.
// Waits for both context-ready bytes and global control, clears shared screen resources then selects transition callback.
extern "C" void System_AdvanceScreenAfterContextReadiness(){if(WfcUtility_IsScreenTransitionBusy(0))return;if(!WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[0]&&WfcUtility_IsScreenTransitionBusy(1))return;if(!WfcUtility_IsBottomButtonBarAbsentOrNotClosing())return;WfcUtility_DestroyAnimatedStatusSprite();Graphics_ClearIndexedMainBackgroundCharacterData(0);if(!WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[0]){Overlay_ProcessPendingFlag();WfcUtility_DisableDisplayPlanes(1,1);}WfcUtility_DisableDisplayPlanes(0,21);if(!WfcMultiScreenDispatchTaskResult_UnknownRoleZeroInitializedStorage[0]){System_ValidateThenFreeSharedGlobalAllocation();WfcUtility_SetNavigationContext(2,1);WfcUtility_SetMainLoopCallback(WfcConnectionMethod_InitializeChooser);}else{WfcUtility_SetNavigationContext(0,0);WfcUtility_SetMainLoopCallback(System_InitializeMode2AAndScheduleCallback);}}
