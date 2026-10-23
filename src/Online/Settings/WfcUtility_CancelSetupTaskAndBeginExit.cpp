#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2290c80; symbol: data_ov031_02290c80.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage[]; extern "C" int WfcUtility_GetBottomButtonSelection(void); extern "C" void WfcUtility_RequestTaskRemoval(unsigned,void*); extern "C" void WfcUtility_DisableBottomButtonTouch(void); extern "C" void WfcUtility_SetMainLoopCallback(void (*)(void)); extern "C" void System_InitializeCallbackStateAndInstallMainLoopCallback(void);
// Original: arm9/ov031 @ 0x0222B1A4; symbol: InitializeSharedResourceAndInstallMainLoopCallback. Initializes the main-loop callback when shared state permits.
extern "C" void WfcUtility_CancelSetupTaskAndBeginExit(void) { if(WfcUtility_GetBottomButtonSelection()!=0)return; void *resource=*(void **)(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage+4); if(!resource)return; WfcUtility_RequestTaskRemoval(1,resource); *(void **)(WfcUtilityUpdateSetupTimeout_UnknownRoleZeroInitializedStorage+4)=0; WfcUtility_DisableBottomButtonTouch(); WfcUtility_SetMainLoopCallback(System_InitializeCallbackStateAndInstallMainLoopCallback); }
