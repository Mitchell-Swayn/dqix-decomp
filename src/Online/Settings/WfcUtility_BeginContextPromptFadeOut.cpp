#include <globaldefs.h>
ARM
extern "C" unsigned WfcUtility_IsScreenTransitionBusy(int);
// Original data: arm9/ov031 @ 0x2290c7c; symbol: data_ov031_02290c7c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage;
extern "C" int WfcUtility_IsConnectionContextAbsent();
extern "C" void System_SetReadyAndScheduleWordCallback();
extern "C" void WfcUtility_StartScreenBrightnessTransition(int,int,int,int);
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_FinishContextPromptExit();
// Original: arm9/ov031 @ 0x0222ACC0; symbol: StartContextThreeTransitionAndInstallCallback; size: 0x80.
extern "C" void WfcUtility_BeginContextPromptFadeOut() {
 if(WfcUtility_IsScreenTransitionBusy(1))return;
 if(!SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage && !WfcUtility_IsConnectionContextAbsent())return;
 System_SetReadyAndScheduleWordCallback();
 if(!SystemInitializeModeCallbacks_UnknownRoleZeroInitializedStorage)WfcUtility_StartScreenBrightnessTransition(3,1,1,8);
 WfcUtility_StartScreenBrightnessTransition(3,0,21,8);WfcUtility_SetMainLoopCallback(WfcUtility_FinishContextPromptExit);
}
