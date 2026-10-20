// Original: arm9/main @ 0x020E5E2C; symbol: __sinit_020e5e2c; size: 0x88.
#include <globaldefs.h>
// Original data: arm9/main @ 0x20f0420; symbol: data_020f0420.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 00003443ffffffff0000f0410000f04100003443.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[5];
// Original data: arm9/main @ 0x21079cc; symbol: data_021079cc.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float Sinit020E5E2C_UnknownRoleZeroInitializedStorage[5];
// ARM9 main, original ABI initializer __sinit_020e5e2c at 0x020e5e2c.
// Initializes a float sum table; the ABI-required initializer name is preserved.
#pragma define_section init ".init" RX
extern "C" ARM __declspec(section "init") void __sinit_020e5e2c(void)
{
    Sinit020E5E2C_UnknownRoleZeroInitializedStorage[1] = GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[3] + (GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[0] + (GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[4] + GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[2]));
    float sum = Sinit020E5E2C_UnknownRoleZeroInitializedStorage[0] + GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[4];
    float addend = GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[2];
    Sinit020E5E2C_UnknownRoleZeroInitializedStorage[4] = sum;
    sum += addend;
    addend = GameObjectResetSavedIdentityAndTransform_UnknownRoleInitializedBytes[0];
    Sinit020E5E2C_UnknownRoleZeroInitializedStorage[3] = sum;
    sum += addend;
    Sinit020E5E2C_UnknownRoleZeroInitializedStorage[2] = sum;
}
