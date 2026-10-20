#pragma once

// Bounds and bank metadata for the five texture-image allocation pools.
struct Struct_020f1f14
{
    unsigned long freeStart_;
    unsigned long freeEnd_;
    unsigned int maybeIsUsable_;
    unsigned int halfSize_;
    unsigned short relatedToPairing_;
    char unk_12[2];
    unsigned int poolBase_;
// Original data: arm9/main @ 0x20f1f14; symbol: data_020f1f14.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex ffffffffffffffff00000000000000000000ffff00000000ffffffffffffffff00000000010000000100ffff00000200ffffffffffffffff0000000001000000 ...; full span in module reference.
// Observed span: 120 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
} extern ResetTextureImageVRAM_UnknownRoleInitializedBytes[5];

// Storage includes two untouched zero bytes after the 16-bit bank count.
struct TextureImageVRAMConfig
{
    unsigned short bankCount;
    unsigned short reserved;
};
// Original data: arm9/main @ 0x210cf84; symbol: data_0210cf84.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern TextureImageVRAMConfig ResetTextureImageVRAM_UnknownRoleZeroInitializedStorage;
