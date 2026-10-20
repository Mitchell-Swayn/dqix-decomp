#include <globaldefs.h>
ARM
#include <System/GamecardBusOwnership.h>
THUMB
extern "C" void CpuSet(const void*,void*,unsigned);
ARM
// Original data: arm9/main @ 0x2112148; symbol: data_02112148.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
// Original data: arm9/main @ 0x211214c; symbol: data_0211214c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char IPCHandleChannelThirteenCompletion_UnknownRoleZeroInitializedStorage[];extern unsigned char CartridgeIsExistingCartridge_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020D12E4; symbol: func_020d12e4; size: 0x38.
extern "C" void ClearGlobalWordAndGenerateLockOwnerId(){unsigned zero=0;CpuSet(&zero,IPCHandleChannelThirteenCompletion_UnknownRoleZeroInitializedStorage,0x05000001);*(unsigned short*)(CartridgeIsExistingCartridge_UnknownRoleZeroInitializedStorage+6)=GenerateLockOwnerID();}
