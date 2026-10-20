#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
extern "C" void MBi_StartParentCore(void *);
// Original: arm9/ov027 @ 0x021DCC24; symbol: func_ov027_021dcc24; size: 0x24.
extern "C" void Network_SetParentStartFlagAndInvokeHandler(void *argument) {
    *(unsigned int *)((unsigned char *)*(void **)(MBEnd_UnknownRoleZeroInitializedStorage + 0xC) + 0x1320) = 1;
    MBi_StartParentCore(argument);
}
