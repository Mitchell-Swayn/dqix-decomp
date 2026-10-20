#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
#pragma optimization_level 4
bool IsContextInactive(ProcessorContext*);
// Original data: arm9/ov031 @ 0x224e60c; symbol: data_ov031_0224e60c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char* WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage;
extern "C" void WfcNetCheck_RunCaptivePortalWorker();
// Original: arm9/ov031 @ 0x02219238; symbol: func_ov031_02219238; size: 0x88.
extern "C" void System_StartOverlay31ContextWhenInactive() {
if(*(unsigned int*)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage+0x1188) && !IsContextInactive((ProcessorContext*)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage+0x111c)))return;
PopulateProcessorContext((ProcessorContext*)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage+0x111c),(unsigned int)WfcNetCheck_RunCaptivePortalWorker,(unsigned int)WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage,(unsigned int)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage+0x1000),0x1000,16);
MarkContextReadyAndSwitch((ProcessorContext*)(WfcNetCheckGetResultCode_UnknownRoleZeroInitializedStorage+0x111c));
}
