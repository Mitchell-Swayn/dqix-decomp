#include <globaldefs.h>
// Original data: arm9/ov031 @ 0x224e204; symbol: data_ov031_0224e204.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" void* NetworkRecycleSocketCommand_UnknownRoleZeroInitializedStorage;
extern "C" int OS_SendMessage(void* queue, void* message, int flags);
// Sends the input value to the overlay queue when it is nonzero.
// Original: arm9/ov031 @ 0x02205174; symbol: func_ov031_02205174; size: 0x20.
extern "C" ARM void Network_RecycleSocketCommand(void* message)
{
    if (message) OS_SendMessage(&NetworkRecycleSocketCommand_UnknownRoleZeroInitializedStorage, message, 0);
}
