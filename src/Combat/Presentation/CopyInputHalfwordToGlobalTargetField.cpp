#include <globaldefs.h>
ARM
#pragma opt_propagation off
struct Input {char unknown[8];unsigned short value;};
struct TargetRegion {char unknown[0x14];unsigned short value;};
struct GlobalState {char unknown[12];char* target;};
// Original data: arm9/ov025 @ 0x21ef988; symbol: data_ov025_021ef988.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov025.md.
extern "C" GlobalState CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov025 @ 0x021E62A8; symbol: func_ov025_021e62a8; size: 0x20.
// Copies input+8 into the target subregion at +0x540, halfword +0x14.
// Region names describe observed offsets; the target object owner is unknown.
extern "C" int CopyInputHalfwordToGlobalTargetField(Input* input) {
 unsigned short value=input->value;
 TargetRegion* region=(TargetRegion*)(CombatSetActionCueFlags_UnknownRoleZeroInitializedStorage.target+0x540);
 region->value=value;
 return 1;
}
