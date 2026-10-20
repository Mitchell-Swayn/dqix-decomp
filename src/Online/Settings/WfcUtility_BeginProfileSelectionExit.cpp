#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290cc0; symbol: data_ov031_02290cc0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[];
extern "C" char* WfcUtility_GetEditableConnectionProfile();
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int,int,int,int);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void System_ResetDisplayObjectsAndSelectMainLoop();
// Original: arm9/ov031 @ 0x02232AC0; symbol: StartContextThreeTransitionFromSharedEntryState; size: 0x84.
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
extern "C" void WfcUtility_BeginProfileSelectionExit() {
 if(WfcUtility_IsScreenTransitionBusy(1))return;
 if(*(unsigned char*)(*(char**)(ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage+4)+29)==1 && (ConfigureSecondContextDisplay_UnknownRoleZeroInitializedStorage[0]==3 || *(unsigned char*)(WfcUtility_GetEditableConnectionProfile()+0xe7)!=255))System_SetReadyAndScheduleWordCallback();
 WfcUtility_StartScreenBrightnessTransition(3,1,1,8);WfcUtility_StartScreenBrightnessTransition(3,0,20,8);WfcUtility_SetMainLoopCallback(System_ResetDisplayObjectsAndSelectMainLoop);
}
