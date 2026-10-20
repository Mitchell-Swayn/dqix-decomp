#include <globaldefs.h>
ARM
// Original data: arm9/main @ 0x2111304; symbol: data_02111304.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern unsigned char OSInitThread_UnknownRoleZeroInitializedStorage_Variant2[];
extern "C" void Network_InitializeCurrentThreadSocket(void);
// Original: arm9/ov031 @ 0x0220321C; symbol: func_ov031_0220321c; size: 0x34.
extern "C" void Network_InitializeCurrentThreadSocket(void) {
    void *base = *(void **)(OSInitThread_UnknownRoleZeroInitializedStorage_Variant2 + 4);
    void *object = *(void **)((char *)base + 0xA4);
    if (object == 0) return;
    *(void **)object = base;
    *(unsigned char *)((char *)object + 8) = 0;
    *(unsigned int *)((char *)object + 0x44) = 0;
    *(unsigned int *)((char *)object + 0x60) = 0;
    *(unsigned int *)((char *)object + 0x38) = 0;
}
