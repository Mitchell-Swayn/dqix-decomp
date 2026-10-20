#include <globaldefs.h>
ARM
// Original data: arm9/ov009 @ 0x218aa70; symbol: data_ov009_0218aa70.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex b80e9f10350e28100a0fae0f2410330f1e0fb40eb80e5110390efb0fe10e850f2410330fb80eb40e.
// Observed span: 40 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov009.md.
extern "C" unsigned char CharacterCreationReadBodyScalePreset_UnknownRoleInitializedBytes[];
// Original: arm9/ov009 @ 0x02188BF8; symbol: func_ov009_02188bf8; size: 0x34.
extern "C" void CharacterCreation_ReadBodyScalePreset(void *a, int index, short *outA, short *outB) {
    unsigned char row = *(unsigned char *)((char *)a + 0xDA3);
    char *entry = (char *)CharacterCreationReadBodyScalePreset_UnknownRoleInitializedBytes + row * 0x14;
    *outA = *(short *)(entry + index * 4);
    *outB = *(short *)(entry + index * 4 + 2);
}
