#include <globaldefs.h>
#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>

extern "C" const unsigned int data_020e7b70[];

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
        StageMemoryToVRAM((VRAMSubregion)(data_020e7b70[region] + offset * 2), source->data, *destOffset, length, true, false);
    }
}
