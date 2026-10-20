#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c98; symbol: data_ov031_02290c98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" int System_IsTaskAvailable();extern "C" char* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;extern "C" void WfcUtility_SetMainLoopCallback(void(*)());extern "C" void WfcUtility_ReleaseIpv4Editor();extern "C" void System_InstallCallbackWhenSharedByte1BIsZero();extern "C" void WfcUtility_OpenIpv4ConfirmationPrompt();extern "C" void WfcUtility_CreateSlidingDialog(int,int,int,int,int);
// Original: arm9/ov031 @ 0x0222DE54; symbol: DispatchTaskModeAndSetMainLoopCallback; size: 0x8C.
// Selects callback and task parameters from shared byte15 when the prior task is unavailable.
extern "C" void DispatchTaskModeAndSetMainLoopCallback(){if(System_IsTaskAvailable())return;unsigned mode=*(unsigned char*)(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage+0x15);if(!mode){WfcUtility_SetMainLoopCallback(WfcUtility_ReleaseIpv4Editor);return;}if(mode==2){WfcUtility_CreateSlidingDialog(6,3,1,-1,0);WfcUtility_SetMainLoopCallback(System_InstallCallbackWhenSharedByte1BIsZero);}else {WfcUtility_CreateSlidingDialog(71,2,1,-1,0);WfcUtility_SetMainLoopCallback(WfcUtility_OpenIpv4ConfirmationPrompt);}}
