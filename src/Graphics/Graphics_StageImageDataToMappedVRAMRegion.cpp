#include <globaldefs.h>
#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>

// Original data: arm9/main @ 0x20e7b70; symbol: data_020e7b70.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 040000000d0000002000200040002000200040004000400010001000200020004000400080008000.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const unsigned int GraphicsStageImageDataToMappedVRAMRegion_UnknownRoleInitializedBytes[];

struct StagedImageSource {
    char pad0[0xc];
    unsigned int length;    // 0xc
    unsigned char data[1];  // 0x10
};

// Original: arm9/main @ 0x0204A9C4; symbol: func_0204a9c4; size: 0x64.
extern "C" void Graphics_StageImageDataToMappedVRAMRegion(unsigned int* destOffset, int region, int offset, StagedImageSource* source) {
    if (source != 0) {
        unsigned int length;
        memcpy(&length, &source->length, 4);
        StageMemoryToVRAM((VRAMSubregion)(GraphicsStageImageDataToMappedVRAMRegion_UnknownRoleInitializedBytes[region] + offset * 2), source->data, *destOffset, length, true, false);
    }
}
