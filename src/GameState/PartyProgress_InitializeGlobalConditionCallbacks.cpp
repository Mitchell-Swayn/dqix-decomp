#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2108f0c; symbol: data_02108f0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 180 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char PartyProgressGetInstance_UnknownRoleZeroInitializedStorage[];
void PartyProgress_InitializeConditionCallbacks(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E628C; symbol: __sinit_020e628c; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e628c()
{
    PartyProgress_InitializeConditionCallbacks(PartyProgressGetInstance_UnknownRoleZeroInitializedStorage);
}
