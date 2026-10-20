#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e1cc; symbol: data_ov031_0224e1cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void *DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage;
extern "C" int DrainNoncurrentUnflaggedContextNodes();
extern "C" void Network_RequestSocketClose(void*);
extern "C" int Util_ValidateNonnegativeValue(void*);
extern "C" void Network_DestroyClosedSockets();
extern "C" int System_PollContextAndDrainQueue();
extern "C" void Network_SetDcfReceiveCallback(int);
// Original: arm9/ov031 @ 0x02206D90; symbol: System_PollSharedSequenceAndDrainQueue; size: 0x7c.
// Polls the shared sequence and drains its pending queue, returning -26 at completion.
extern "C" int System_PollSharedSequenceAndDrainQueue() {
 int result;
 if (DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage) {
  result=DrainNoncurrentUnflaggedContextNodes();
  if (!result) {
   Network_RequestSocketClose(DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage);
   if(Util_ValidateNonnegativeValue(DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage)) DrainNoncurrentUnflaggedContextNodes_UnknownRoleZeroInitializedStorage=0;
   result=-26;
  }
  Network_DestroyClosedSockets();
 } else if(!System_PollContextAndDrainQueue()) result=-26;
 else { Network_SetDcfReceiveCallback(0); result=0; }
 return result;
}
