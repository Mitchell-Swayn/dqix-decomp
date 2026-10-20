#pragma thumb off
#pragma define_section init ".init" RX
// Original data: arm9/main @ 0x20f0b30; symbol: data_020f0b30.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000f041000034430000f04100003443.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern float Sinit020E5F9C_UnknownRoleInitializedBytes[4];
// Original data: arm9/main @ 0x2108d48; symbol: data_02108d48.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern float Sinit020E5F9C_UnknownRoleZeroInitializedStorage[5];
// Original: arm9/main @ 0x020E5F9C; symbol: __sinit_020e5f9c; size: 0x88.
// Initialize cumulative float boundaries from four existing spacing constants.
extern "C" __declspec(section "init") void __sinit_020e5f9c()
{
    Sinit020E5F9C_UnknownRoleZeroInitializedStorage[3] = Sinit020E5F9C_UnknownRoleInitializedBytes[0] + (Sinit020E5F9C_UnknownRoleInitializedBytes[1] + (Sinit020E5F9C_UnknownRoleInitializedBytes[3] + Sinit020E5F9C_UnknownRoleInitializedBytes[2]));
    float boundary = Sinit020E5F9C_UnknownRoleZeroInitializedStorage[2] + Sinit020E5F9C_UnknownRoleInitializedBytes[3];
    float spacing = Sinit020E5F9C_UnknownRoleInitializedBytes[2];
    Sinit020E5F9C_UnknownRoleZeroInitializedStorage[1] = boundary;
    boundary += spacing;
    spacing = Sinit020E5F9C_UnknownRoleInitializedBytes[1];
    Sinit020E5F9C_UnknownRoleZeroInitializedStorage[0] = boundary;
    Sinit020E5F9C_UnknownRoleZeroInitializedStorage[4] = boundary + spacing;
}
