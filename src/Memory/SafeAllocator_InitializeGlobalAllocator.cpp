#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x210783c; symbol: data_0210783c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage[];
void SafeAllocator_ResetAndReturnPointer(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5D84; symbol: __sinit_020e5d84; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e5d84()
{
    SafeAllocator_ResetAndReturnPointer(TextInitializeSharedContextAndResources_UnknownRoleZeroInitializedStorage);
}
