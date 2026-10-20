#include <globaldefs.h>
ARM
extern "C" unsigned Network_GetConnectionPhase();
// Original data: arm9/ov031 @ 0x224e5c4; symbol: data_ov031_0224e5c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 20 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02213024; symbol: System_ReadObjectByte17ForContextByte9Range10To16; size: 0x30.
// Returns 0xff outside context-byte values 10..16; within that range, returns byte +0x17 from the selected object.
extern "C" unsigned System_ReadObjectByte17ForContextByte9Range10To16(void) {
    unsigned result = 0xff;
    unsigned value = Network_GetConnectionPhase();
    if (value >= 10 && value <= 16)
        result = *(unsigned char *)(*(unsigned int *)(NetworkGetConnectionPhase_UnknownRoleZeroInitializedStorage + 0x0c) + 0x17);
    return result;
}
