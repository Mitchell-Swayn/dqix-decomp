#include <globaldefs.h>
ARM
struct Callbacks {void (*handlers[5])(void*);};
// Original data: arm9/ov031 @ 0x2248f0c; symbol: data_ov031_02248f0c.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 745e2302905e2302ac5e2302cc5e2302ec5e2302.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Callbacks WfcUtilityApplyIpv4EditorResultOrResume_UnknownRoleProcedureReferenceRecords;
// Original data: arm9/ov031 @ 0x2290c98; symbol: data_ov031_02290c98.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage;
extern "C" int WfcUtility_IsDialogActive();
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
extern "C" void InitializeIdleSelectionAndSetMainLoopCallback();
extern "C" void WfcUtility_ReleaseIpv4Editor();
// Original: arm9/ov031 @ 0x0222E0F8; symbol: func_ov031_0222e0f8; size: 0xB4.
extern "C" void WfcUtility_ApplyIpv4EditorResultOrResume() {
Callbacks callbacks=WfcUtilityApplyIpv4EditorResultOrResume_UnknownRoleProcedureReferenceRecords;
if(WfcUtility_IsDialogActive()) return;
if(!*(unsigned char*)(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage+0x15)) {
**(unsigned**)(WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage+4)&=0xc1fffcff;
WfcUtility_SetMainLoopCallback(InitializeIdleSelectionAndSetMainLoopCallback);
return;
}
unsigned index;
WfcUtility_GetScreenOperationArguments(&index,0);
callbacks.handlers[index](WfcUtilityReleaseIpv4Editor_UnknownRoleZeroInitializedStorage+8);
WfcUtility_SetMainLoopCallback(WfcUtility_ReleaseIpv4Editor);
}
