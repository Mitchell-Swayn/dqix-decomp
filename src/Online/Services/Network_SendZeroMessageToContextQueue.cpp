#include <globaldefs.h>
ARM
extern "C" int OS_SendMessage(void *, void *, int);
// Original data: arm9/ov031 @ 0x22918bc; symbol: data_ov031_022918bc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int HttpWaitForRequestQueueMessage_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022403F4; symbol: func_ov031_022403f4; size: 0x1C.
extern "C" int Network_SendZeroMessageToContextQueue(void) { return OS_SendMessage(&HttpWaitForRequestQueueMessage_UnknownRoleZeroInitializedStorage, 0, 0); }
