#include <globaldefs.h>
extern "C"
{
// Original data: arm9/main @ 0x2105ab4; symbol: data_02105ab4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 1316 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char GraphicsGetGlobalOamTransferState_UnknownRoleZeroInitializedStorage[];
// Original data: arm9/main @ 0x2105248; symbol: data_02105248.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
    extern unsigned char Sinit020E5C2C_UnknownRoleZeroInitializedStorage[];
    void* TextSprite_ConstructRenderer(void*);
    void* TextSprite_DestroyRenderer(void*);
    void __register_global_object(void*, void (*)(void*, int), void*);
}
#pragma define_section init ".init" RX
// Original: arm9/main @ 0x020E5C2C; symbol: __sinit_020e5c2c; size: 0x2C.
extern "C" __declspec(section "init") void __sinit_020e5c2c()
{
    TextSprite_ConstructRenderer(GraphicsGetGlobalOamTransferState_UnknownRoleZeroInitializedStorage);
    __register_global_object(GraphicsGetGlobalOamTransferState_UnknownRoleZeroInitializedStorage, (void (*)(void*, int))TextSprite_DestroyRenderer, Sinit020E5C2C_UnknownRoleZeroInitializedStorage);
}
