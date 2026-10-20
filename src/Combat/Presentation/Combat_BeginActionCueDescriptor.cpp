#include <globaldefs.h>
ARM
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" unsigned CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
extern "C" void Combat_InitializeActionEffectDescriptor(void *);
// Original: arm9/ov025 @ 0x021E6208; symbol: Unclassified_InitializeGlobalField540AndStoreValue; size: 0x28.
// Loads the pointer stored at data_ov025_021ef988+0x0C, initializes its field at +0x540, stores the second argument there, and returns 1.
extern "C" unsigned Combat_BeginActionCueDescriptor(void *unused, unsigned value) {
    char *base = *(char **)((char *)&CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage + 0xc);
    Combat_InitializeActionEffectDescriptor(base + 0x540);
    *(unsigned *)(base + 0x540) = value;
    return 1;
}
