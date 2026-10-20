#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x21077dc; symbol: data_021077dc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char Sinit020E5Ce8_UnknownRoleZeroInitializedStorage[];
void ClearWordAndTwoBytesAndReturnPointer(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5CE8; symbol: __sinit_020e5ce8; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e5ce8()
{
    ClearWordAndTwoBytesAndReturnPointer(Sinit020E5Ce8_UnknownRoleZeroInitializedStorage);
}
