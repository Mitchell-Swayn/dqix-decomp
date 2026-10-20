// Original data: arm9/main @ 0x020F0B30; symbol: data_020f0b30; size: 0x10.
// Four IEEE-754 input coefficients consumed by __sinit_020e5f9c.
// The initializer reads every element as float and constructs cumulative sums.
// Original initialized values: 30.0f, 180.0f, 30.0f, 180.0f
// (words 0x41F00000, 0x43340000, 0x41F00000, 0x43340000).
// These writable inputs are distinct copies; their higher-level purpose is unresolved.
extern "C" {
float Sinit020E5F9C_UnknownRoleInitializedBytes[4] = { 30.0f, 180.0f, 30.0f, 180.0f };
}
