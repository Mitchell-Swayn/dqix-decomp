// Original data: arm9/main @ 0x020EFE5C; symbol: data_020efe5c; size: 0x10.
// Four IEEE-754 input coefficients consumed by Math_InitializeCumulativeFloatValues.
// The initializer reads every element as float and constructs cumulative sums.
// Original initialized values: 30.0f, 180.0f, 30.0f, 180.0f
// (words 0x41F00000, 0x43340000, 0x41F00000, 0x43340000).
// These writable inputs are distinct copies; their higher-level purpose is unresolved.
extern "C" {
float MathInitializeCumulativeFloatValues_UnknownRoleInitializedBytes[4] = { 30.0f, 180.0f, 30.0f, 180.0f };
}
