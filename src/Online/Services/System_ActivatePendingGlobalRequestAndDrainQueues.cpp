#include <globaldefs.h>
ARM
#pragma opt_propagation off
#pragma opt_common_subs off
// Original data: arm9/ov031 @ 0x2290fcc; symbol: data_ov031_02290fcc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage;
extern "C" void System_LockGlobalMutex();
extern "C" void System_ProcessGlobalQueueUntilEmpty();
extern "C" void Http_UnlockRequestQueueMutex();
extern "C" void Http_ShutdownSocketWhenValid(unsigned,int);
// Original: arm9/ov031 @ 0x02240F74; symbol: func_ov031_02240f74; size: 0x54.
// Marks the pending request status, dispatches its two fields, then drains handlers.
// Word views preserve aliasing; request field reads repeat across the status test/write.
extern "C" void System_ActivatePendingGlobalRequestAndDrainQueues() {
 System_LockGlobalMutex();
 volatile unsigned* node=(volatile unsigned*)HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage;
 if(node && ((unsigned*)node[3])[1]==0) {
  ((unsigned*)node[3])[1]=1;
  node=(volatile unsigned*)HttpRunQueuedRequestWorker_UnknownRoleZeroInitializedStorage;
  Http_ShutdownSocketWhenValid(node[3],node[4]);
 }
 System_ProcessGlobalQueueUntilEmpty();
 Http_UnlockRequestQueueMutex();
}
