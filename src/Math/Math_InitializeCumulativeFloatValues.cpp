#pragma thumb off
#pragma define_section init ".init" RX
// Original data: arm9/main @ 0x20efe5c; symbol: data_020efe5c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0000f041000034430000f04100003443.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[4];
// Original data: arm9/main @ 0x21077e8; symbol: data_021077e8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" float MathInitializeCumulativeFloatValues_UnknownRoleZeroInitializedStorage[5];
// Initializes total and reverse cumulative sums; slot3 is the existing starting value.
// The next coefficient is read before storing slot2, matching the original access order.
// Original: arm9/main @ 0x020E5CFC; symbol: __sinit_020e5cfc; size: 0x88.
extern "C" __declspec(section "init") void Math_InitializeCumulativeFloatValues(void)
{
 MathInitializeCumulativeFloatValues_UnknownRoleZeroInitializedStorage[4]=MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[0]+(MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[1]+(MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[3]+MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[2]));
 float value=MathInitializeCumulativeFloatValues_UnknownRoleZeroInitializedStorage[3]+MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[3];
 float coefficient=MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[2];
 MathInitializeCumulativeFloatValues_UnknownRoleZeroInitializedStorage[2]=value;
 value+=coefficient;
 MathInitializeCumulativeFloatValues_UnknownRoleZeroInitializedStorage[1]=value;
 value+=MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[1];
 MathInitializeCumulativeFloatValues_UnknownRoleZeroInitializedStorage[0]=value;
}
