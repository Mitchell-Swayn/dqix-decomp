#include <globaldefs.h>
ARM
// Original data: arm9/ov017 @ 0x21d847c; symbol: data_ov017_021d847c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 28 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov017.md.
extern "C" int NetworkApplySharedCommandValue_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov017 @ 0x021D3EB4; symbol: func_ov017_021d3eb4; size: 0x14.
extern "C" void Network_ApplySharedCommandValue(int a0, int a1) {
    NetworkApplySharedCommandValue_UnknownRoleZeroInitializedStorage = *(int *)(a1 + 4);
}
