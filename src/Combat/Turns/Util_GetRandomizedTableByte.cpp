#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct Random;
struct ByteTable { char bytes[12]; };
// Original data: arm9/ov000 @ 0x2182a85; symbol: data_ov000_02182a85.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 000000000204000703000100000000.
// Observed span: 15 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov000.md.
extern "C" ByteTable UtilGetRandomizedTableByte_UnknownRoleInitializedBytes;
extern "C" int _Z17NextRandomBetweenP6Randomii(Random*, int, int);
// Original: arm9/ov000 @ 0x0215FBE0; symbol: func_ov000_0215fbe0; size: 0x80.
extern "C" int Util_GetRandomizedTableByte(Random* random, int index) {
    ByteTable table = UtilGetRandomizedTableByte_UnknownRoleInitializedBytes;
    table.bytes[3] = _Z17NextRandomBetweenP6Randomii(random, 3, 4);
    table.bytes[11] = _Z17NextRandomBetweenP6Randomii(random, 6, 8);
    char* bytes = table.bytes;
    return index < 0 || index >= 12 ? 0 : bytes[index];
}
