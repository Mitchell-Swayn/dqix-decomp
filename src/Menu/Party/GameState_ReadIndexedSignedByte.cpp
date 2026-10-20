#include <globaldefs.h>
ARM
// Original data: arm9/ov002 @ 0x216c9dc; symbol: data_ov002_0216c9dc.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000000002000000010000000300000004000000050000000600000008.
// Observed span: 29 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov002.md.
extern "C" int GameStateReadIndexedSignedByte_UnknownRoleInitializedBytes[];
// Original: arm9/ov002 @ 0x0215A9F0; symbol: func_ov002_0215a9f0; size: 0x24.
extern "C" int GameState_ReadIndexedSignedByte(void *object) {
    int index = *(short *)((char *)object + 0x1c0a);
    int offset = GameStateReadIndexedSignedByte_UnknownRoleInitializedBytes[index];
    return *(signed char *)((char *)object + offset + 0x1c7c);
}
