#include <globaldefs.h>
ARM
// Original data: arm9/ov027 @ 0x21e33e0; symbol: data_ov027_021e33e0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov027.md.
extern "C" unsigned char MBEnd_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov027 @ 0x021DD04C; symbol: func_ov027_021dd04c; size: 0x60.
extern "C" unsigned char MBi_GetAttribute(void) {
    unsigned char *state = *(unsigned char **)(MBEnd_UnknownRoleZeroInitializedStorage + 8);
    unsigned int bit2 = *(unsigned short *)(state + 0x12) != 0 ? 2 : 0;
    unsigned int bit1 = *(unsigned short *)(state + 0x0e) != 0 ? 1 : 0;
    unsigned int bit4 = *(unsigned short *)(state + 0x14) != 0 ? 4 : 0;
    unsigned int bit8 = *(unsigned short *)(state + 0x16) != 0 ? 8 : 0;

    return bit1 | bit2 | bit4 | bit8;
}
