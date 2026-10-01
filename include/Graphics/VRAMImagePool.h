#pragma once

// Bounds and bank metadata for the five texture-image allocation pools.
struct Struct_020f1f14
{
    unsigned int freeStart_;
    unsigned int freeEnd_;
    unsigned int maybeIsUsable_;
    unsigned int halfSize_;
    unsigned short relatedToPairing_;
    char unk_12[2];
    unsigned int poolBase_;
} extern data_020f1f14[5];

// Storage includes two untouched zero bytes after the 16-bit bank count.
struct TextureImageVRAMConfig
{
    unsigned short bankCount;
    unsigned short reserved;
};
extern TextureImageVRAMConfig data_0210cf84;
