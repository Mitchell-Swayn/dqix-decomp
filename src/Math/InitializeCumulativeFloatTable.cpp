#include <globaldefs.h>
// Original data: arm9/main @ 0x20f0d1c; symbol: data_020f0d1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000f041000034430000f04100003443.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[];
// Original data: arm9/main @ 0x2108dc4; symbol: data_02108dc4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[];
// Original: arm9/main @ 0x020E6038; symbol: __sinit_020e6038; size: 0x88.
// Constructs cumulative floating-point values from a four-element input table.
#pragma define_section init ".init" RX
extern "C" __declspec(section "init") void Math_InitializeCumulativeFloatTable() {
 MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[4]=((MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[3]+MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[2])+MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[1])+MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[0];
 MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[2]=MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[3]+MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[3];
 MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[1]=MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[2]+MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[2];
 MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[0]=MathInitializeCumulativeFloatTable_UnknownRoleZeroInitializedStorage[1]+MathInitializeCumulativeFloatTable_UnknownRoleInitializedBytes[1];
}
