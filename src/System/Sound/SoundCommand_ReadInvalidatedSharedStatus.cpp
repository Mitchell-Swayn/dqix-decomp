#include <globaldefs.h>
#include <std_library_functions.h>
#include <System/Cache.h>
extern "C" {
// Original data: arm9/main @ 0x21142c0; symbol: data_021142c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned int *InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage;
// Original: arm9/main @ 0x020D29F4; symbol: func_020d29f4; size: 0x2C.
unsigned int SoundCommand_ReadInvalidatedSharedStatus(){InvalidateDataCacheRange(InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage+1,4);return InvalidateAndReadSharedWord_UnknownRoleZeroInitializedStorage[1];}
}
