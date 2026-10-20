#include <globaldefs.h>
extern "C" int MB_CommIsBootable(int);
// Original data: arm9/ov031 @ 0x2290d14; symbol: data_ov031_02290d14.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char MultibootGetParentState_UnknownRoleZeroInitializedStorage[];
// Original: arm9/ov031 @ 0x02238C40; symbol: func_ov031_02238c40; size: 0x68.
extern "C" int Multiboot_AreAllConnectedChildrenBootable(void) {
    volatile unsigned char * volatile *global = (volatile unsigned char * volatile *)MultibootGetParentState_UnknownRoleZeroInitializedStorage;
    if (*(unsigned short *)(*global + 2) == 0) return 0;
    unsigned short index = 1;
    do {
        unsigned short flags = *(unsigned short *)(*global + 2);
        if ((flags & (1u << index)) && !MB_CommIsBootable(index)) return 0;
        ++index;
    } while (index < 0x10);
    return 1;
}
