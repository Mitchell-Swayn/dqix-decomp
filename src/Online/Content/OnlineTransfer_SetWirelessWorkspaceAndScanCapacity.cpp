#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2291f24; symbol: data_ov031_02291f24.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 24 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02245858; symbol: func_ov031_02245858; size: 0x14.
extern "C" void OnlineTransfer_SetWirelessWorkspaceAndScanCapacity(unsigned int a, unsigned int b) { *(unsigned int*)(WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage + 0x14) = a; WirelessRunConnectionWorker_UnknownRoleZeroInitializedStorage[0] = b; }
