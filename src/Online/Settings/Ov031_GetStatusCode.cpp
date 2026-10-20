#include <globaldefs.h>
ARM
// Original data: arm9/ov031 @ 0x2250c0c; symbol: data_ov031_02250c0c.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 52 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char Ov031GetStatusCode_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov031 @ 0x022275A0; symbol: func_ov031_022275a0; size: 0x40.
extern "C" unsigned int Ov031_GetStatusCode(void) {
    unsigned char status = Ov031GetStatusCode_UnknownRoleZeroInitializedStorage;
    if (status == 6) return 0x38;
    if (status == 1 && ((*(unsigned int *)((char *)&Ov031GetStatusCode_UnknownRoleZeroInitializedStorage + 8) >> 4) & 2) == 0) return 0x37;
    return (status + 0x31) & 0xff;
}
