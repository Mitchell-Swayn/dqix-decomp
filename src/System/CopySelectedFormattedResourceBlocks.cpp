#include <globaldefs.h>
#include <System/Cache.h>
#include <System/LoadToVRAM.h>
struct PaletteResource { unsigned format; unsigned extended; unsigned size; unsigned char* data; };
struct PaletteSelection { unsigned short count, reserved; unsigned short* indices; };
struct PaletteTarget { unsigned format, extended; };
extern "C" void NNS_G2dSetImagePaletteLocation(PaletteTarget*, int, unsigned);
// Original: arm9/main @ 0x020B08B8; symbol: func_020b08b8; size: 0x164.
extern "C" void CopySelectedFormattedResourceBlocks(PaletteResource* resource, PaletteSelection* selection, unsigned base, int target, PaletteTarget* result) {
    int sourceOffset;
    unsigned char* data;
    int targetOffset;
    int stride;
    if (resource->format == 3) stride=32;
    else stride=512;
    unsigned short count = selection->count;
    unsigned i=0;
    if (count != 0) do {
        data = resource->data;
        sourceOffset = stride*i;
        targetOffset = stride*selection->indices[i];
        CleanInvalidateCacheRange(data, resource->size);
        switch (target) {
        case 1:
            if(resource->extended) {
                MemoryMapMainObjExtendedPalette();
                LoadToMainObjExtendedPalette(data+sourceOffset,base+targetOffset,stride);
                MemoryUnmapMainObjExtendedPalette();
            } else LoadToMainObjStandardPalette(data+sourceOffset,base+targetOffset,stride);
            break;
        case 2:
            if(resource->extended) {
                MemoryMapSubObjExtendedPalette();
                LoadToSubObjExtendedPalette(data+sourceOffset,base+targetOffset,stride);
                MemoryUnmapSubObjExtendedPalette();
            } else LoadToSubObjStandardPalette(data+sourceOffset,base+targetOffset,stride);
            break;
        case 0:
            MemoryMapTexturePalette();
            LoadToTexturePalette(data+sourceOffset,base+targetOffset,stride);
            MemoryUnmapTexturePalette();
            break;
        }
    }
    while ((i=(unsigned short)(i+1)) < count);
    result->format=resource->format;
    result->extended=resource->extended;
    NNS_G2dSetImagePaletteLocation(result,target,base);
}
