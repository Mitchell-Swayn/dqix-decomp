#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x0221F994; symbol: func_ov031_0221f994; size: 0xC.
extern "C" int WirelessSetup_GetWirelessDriverState(void) {
    return *(int *)(WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage + 0x2C);
}
