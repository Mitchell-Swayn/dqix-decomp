#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DCEE8; symbol: func_ov027_021dcee8; size: 0x10.
extern "C" void MBi_SetScanDwellTime(unsigned short value) {
    *(unsigned short *)(MBEnd_UnknownRoleZeroInitializedStorage + 0x26) = value;
}
