#include <globaldefs.h>
#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>

extern "C" const unsigned int data_020e7b68[];

struct StagedImageSource {
    char pad0[0xc];
    unsigned int length;    // 0xc
    unsigned char data[1];  // 0x10
};

struct StagedImageState {
    char pad0[8];
    unsigned int length;    // 0x8
};

// Original: arm9/main @ 0x0204ADE8; symbol: func_0204ade8; size: 0x5C.
extern "C" void StageSerializedDataToSelectedVRAMRegion(StagedImageState* state, int region, int offset, StagedImageSource* source) {
    memcpy(&state->length, &source->length, 4);
    StageMemoryToVRAM((VRAMSubregion)(data_020e7b68[region] + offset * 2), source->data, 0, state->length, true, false);
}
