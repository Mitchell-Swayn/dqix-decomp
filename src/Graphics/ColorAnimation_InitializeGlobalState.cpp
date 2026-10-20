#include <globaldefs.h>
extern "C" {
// Original data: arm9/main @ 0x2108d5c; symbol: data_02108d5c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char ColorAnimationGetGlobalInstance_UnknownRoleZeroInitializedStorage[];
void ColorAnimation_Construct(void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E6024; symbol: __sinit_020e6024; size: 0x14.
extern "C" __declspec(section "init") void __sinit_020e6024()
{
    ColorAnimation_Construct(ColorAnimationGetGlobalInstance_UnknownRoleZeroInitializedStorage);
}
