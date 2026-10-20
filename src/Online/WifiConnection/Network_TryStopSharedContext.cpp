#include <globaldefs.h>
#include <System/ProcessorContext.h>
ARM
#pragma optimize_for_size off
struct OSMessageQueue;
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" OSMessageQueue* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
extern "C" int Network_ClearMessageWordsAndTrySend(void*);
extern "C" unsigned System_UnlockAndSwitchReadyContext();
bool IsContextInactive(ProcessorContext*);
// Original: arm9/ov031 @ 0x0220F4BC; symbol: func_ov031_0220f4bc; size: 0x5C.
// Sends a null stop message; clears shared queue after its context becomes inactive.
// Returns one when stopped, zero after scheduling another ready-context attempt.
extern "C" int Network_TryStopSharedContext() {
 if(!StoreReadySharedValue_UnknownRoleZeroInitializedStorage)return 1;
 Network_ClearMessageWordsAndTrySend(0);
 if(!IsContextInactive((ProcessorContext*)((char*)StoreReadySharedValue_UnknownRoleZeroInitializedStorage+0x34))) {
  System_UnlockAndSwitchReadyContext();
  return 0;
 }
 StoreReadySharedValue_UnknownRoleZeroInitializedStorage=0;
 return 1;
}
