#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d616c; symbol: data_ov017_021d616c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 4142434445464748494a53544b4c4d4e4f5051002f28e879ff65.
// Observed span: 26 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" signed char UtilGetSignedTableValue1To19_UnknownRoleInitializedBytes[];
// Original: arm9/ov017 @ 0x0218D2C4; symbol: func_ov017_0218d2c4; size: 0x2C.
extern "C" int Util_GetSignedTableValue1To19(int index) {
    if (index < 1 || index > 19)
        return 0;
    return UtilGetSignedTableValue1To19_UnknownRoleInitializedBytes[index - 1];
}
