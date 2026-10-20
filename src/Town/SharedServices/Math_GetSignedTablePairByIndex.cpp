#include <globaldefs.h>
ARM
// Original data: arm9/ov003 @ 0x217f3b2; symbol: data_ov003_0217f3b2.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1000.
// Observed span: 2 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" short MathGetSignedTablePairByIndex_UnknownRoleInitializedBytes[];
// Original data: arm9/ov003 @ 0x217f3b4; symbol: data_ov003_0217f3b4.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 1000180010002000100058001000400010000000.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov003.md.
extern "C" short MathGetSignedTablePairByIndex_UnknownRoleInitializedBytes_Variant2[];
// Original: arm9/ov003 @ 0x0215EC68; symbol: func_ov003_0215ec68; size: 0x28.
extern "C" void Math_GetSignedTablePairByIndex(unsigned int index, short* a, short* b) { short x = ((volatile short*)MathGetSignedTablePairByIndex_UnknownRoleInitializedBytes)[index * 2]; short y = ((volatile short*)MathGetSignedTablePairByIndex_UnknownRoleInitializedBytes_Variant2)[index * 2]; *a = x; *b = y; }
