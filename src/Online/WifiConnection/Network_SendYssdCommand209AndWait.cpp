#include <globaldefs.h>
ARM
#pragma optimization_level 4
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" char* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" void YssdCommand_RecordTransferSizeReply();
extern "C" int StoreReadySharedValue(void*);
extern "C" int System_CompareWordToGlobalResult(const unsigned*);
extern "C" void YssdCommand_WaitForReplyCompletion();
extern "C" void YssdCommand_ClearReplyHandler();
// Original: arm9/ov031 @ 0x0220FCFC; symbol: SubmitSharedControlDescriptorAndWait; size: 0x7c.
// Initializes a shared-control descriptor with tag DSSY and commandD1, submits callback, waits on readiness.
extern "C" void Network_SendYssdCommand209AndWait(){
 char storage[0x414]; unsigned* descriptor=(unsigned*)storage;
 descriptor[0]=0x10;descriptor[1]=0x44535359;descriptor[2]=0xd1;
 descriptor[3]=*(unsigned*)(*(char**)(StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x24)+4);
 if(StoreReadySharedValue((void*)YssdCommand_RecordTransferSizeReply)){
 if(System_CompareWordToGlobalResult((unsigned*)storage))YssdCommand_WaitForReplyCompletion();}
 YssdCommand_ClearReplyHandler();
}
