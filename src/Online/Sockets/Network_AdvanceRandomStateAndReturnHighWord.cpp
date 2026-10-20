#pragma thumb off
struct RandomState {char pad[0x68];unsigned long long seed,multiplier,increment;};
// Original data: arm9/ov031 @ 0x224c980; symbol: data_ov031_0224c980.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" RandomState NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x02203120; symbol: func_ov031_02203120; size: 0x44.
extern "C" unsigned Network_AdvanceRandomStateAndReturnHighWord() {
 NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.seed=NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.multiplier*NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.seed+NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.increment;
 return NetworkQueryDnsRecord_UnknownRoleZeroInitializedStorage.seed>>32;
}
