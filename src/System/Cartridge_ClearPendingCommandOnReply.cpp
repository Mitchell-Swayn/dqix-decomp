#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2112160; symbol: data_02112160.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 32 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D1940; symbol: func_020d1940; size: 0x14.
void Cartridge_ClearPendingCommandOnReply(){CartridgeHandleRemovalNotification_UnknownRoleZeroInitializedStorage[1]=0;}
}
