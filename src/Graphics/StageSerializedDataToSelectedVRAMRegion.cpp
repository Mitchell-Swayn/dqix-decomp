#include <globaldefs.h>
#include <std_library_functions.h>
#include <Graphics/VRAMStaging.h>

// Original data: arm9/main @ 0x20e7b68; symbol: data_020e7b68.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 030000000c000000.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" const unsigned int StageSerializedDataToSelectedVRAMRegion_UnknownRoleInitializedBytes[];

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
    StageMemoryToVRAM((VRAMSubregion)(StageSerializedDataToSelectedVRAMRegion_UnknownRoleInitializedBytes[region] + offset * 2), source->data, 0, state->length, true, false);
}
