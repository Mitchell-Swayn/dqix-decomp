#include <globaldefs.h>
ARM
#pragma optimization_level 1
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned int OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];

// Original: arm9/ov031 @ 0x02203190; symbol: func_ov031_02203190; size: 0x2C.
extern "C" void Network_EnableUdpSocketMode(void) {
    unsigned char *record = *(unsigned char **)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[1] + 0xa4);
    if (record == 0)
        return;
    record[8] = 10;
    *(unsigned int *)(record + 0x44) = 0;
}
