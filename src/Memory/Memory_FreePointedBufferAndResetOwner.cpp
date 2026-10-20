#include <globaldefs.h>
#include <Resource/Script.h>
ARM
// Original data: arm9/main @ 0x2114e20; symbol: data_02114e20.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage_Variant3[];extern "C" void Memory_FreeThroughAllocatorUnion(void*,void*);extern "C" void Bgm_ResetZoneOverrideTable(void*);
// Original: arm9/main @ 0x0209CD24; symbol: func_0209cd24; size: 0x2C.
extern "C" void Memory_FreePointedBufferAndResetOwner(void** p){if(*p)Memory_FreeThroughAllocatorUnion(Main_UnknownRoleZeroInitializedStorage_Variant3,*p);Bgm_ResetZoneOverrideTable(p);}
