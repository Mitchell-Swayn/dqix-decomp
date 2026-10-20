#include <globaldefs.h>
THUMB
// Original data: arm9/ov031 @ 0x224f670; symbol: data_ov031_0224f670.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x022228B0; symbol: func_ov031_022228b0; size: 0x10.
extern "C" void WirelessSetup_FreeScanList(void* a) { ((void (*)(void*))WirelessSetupRunConfigurationExchange_UnknownRoleZeroInitializedStorage[3])(a); }
