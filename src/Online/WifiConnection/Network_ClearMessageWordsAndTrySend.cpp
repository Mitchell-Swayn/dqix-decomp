#include <globaldefs.h>
ARM
#pragma optimize_for_size off
struct OSMessageQueue;
extern "C" int OS_SendMessage(OSMessageQueue*, void*, int);
// Original data: arm9/ov031 @ 0x224e580; symbol: data_ov031_0224e580.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" OSMessageQueue* StoreReadySharedValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x0220F518; symbol: func_ov031_0220f518; size: 0x40.
// Clears three message words and attempts a nonblocking send to the global queue.
// A null message is still sent when the queue exists.
extern "C" int Network_ClearMessageWordsAndTrySend(void* message)
{
 if (message) {
  *(unsigned*)((char*)message + 0x1c) = 0;
  *(unsigned*)((char*)message + 0x20) = 0;
  *(unsigned*)((char*)message + 0x24) = 0;
 }
 if (!StoreReadySharedValue_UnknownRoleZeroInitializedStorage) return 0;
 return OS_SendMessage(StoreReadySharedValue_UnknownRoleZeroInitializedStorage, message, 0);
}
