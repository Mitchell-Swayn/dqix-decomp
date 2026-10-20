#include <globaldefs.h>
ARM

extern "C" int FastIntDivide(int a, int b);
// Original data: arm9/ov031 @ 0x2290ca0; symbol: data_ov031_02290ca0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov031.md.
extern "C" unsigned char StartMode6ContextCallback_UnknownRoleZeroInitializedStorage[];

// Original: arm9/ov031 @ 0x022305A4; symbol: func_ov031_022305a4; size: 0x44.
extern "C" int WfcSettingsList_FindVisibleRowSlot(int value) {
    int quotient = FastIntDivide(*(unsigned short *)(StartMode6ContextCallback_UnknownRoleZeroInitializedStorage + 4), 0x1d);
    int index = 0;
    do {
        if (quotient == value) {
            return index;
        }
        index++;
        quotient++;
    } while (index < 4);
    return -1;
}
