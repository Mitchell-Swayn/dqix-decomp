#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x224e1c0; symbol: data_ov031_0224e1c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned int NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02205000; symbol: func_ov031_02205000; size: 0x18.
extern "C" void Network_MarkAddressConfigurationReady(void) {
    NetworkInitializeSocketStack_UnknownRoleZeroInitializedStorage[2] |= 2;
}
