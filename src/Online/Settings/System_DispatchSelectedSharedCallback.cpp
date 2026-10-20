#include <globaldefs.h>
ARM
typedef void(*Callback)(void*);
// Original data: arm9/ov031 @ 0x2248eb4; symbol: data_ov031_02248eb4.
// Contains original relocated procedure references. Record fields, dispatch contract and exclusive ownership may remain unresolved.
// Initial values: hex 3e3d0e00100000004700000048000000ac5c2302dc5c2302.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" Callback SystemDispatchSelectedSharedCallback_UnknownRoleProcedureReferenceRecords[];
// Original data: arm9/ov031 @ 0x2290c94; symbol: data_ov031_02290c94.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage;
extern "C" void WfcUtility_SetMainLoopCallback(void(*)());
extern "C" void WfcUtility_GetScreenOperationArguments(unsigned*,unsigned*);
extern "C" int WfcUtility_IsDialogActive();
extern "C" void WfcUtility_ArmWirelessTextEditorInput();
extern "C" void WfcUtility_ReleaseWirelessTextEditor();
// Original: arm9/ov031 @ 0x0222D474; symbol: func_ov031_0222d474; size: 0xB0.
extern "C" void System_DispatchSelectedSharedCallback() {
Callback callbacks[2]={SystemDispatchSelectedSharedCallback_UnknownRoleProcedureReferenceRecords[4],SystemDispatchSelectedSharedCallback_UnknownRoleProcedureReferenceRecords[5]};
if(WfcUtility_IsDialogActive())return;
if(!WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage[0x2a]){
**(unsigned int**)(WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage+4)&=0xc1fffcff;
WfcUtility_SetMainLoopCallback(WfcUtility_ArmWirelessTextEditorInput);return;
}
unsigned int index;WfcUtility_GetScreenOperationArguments(&index,0);
callbacks[index](WfcUtilityReleaseWirelessTextEditor_UnknownRoleZeroInitializedStorage+8);
WfcUtility_SetMainLoopCallback(WfcUtility_ReleaseWirelessTextEditor);
}
