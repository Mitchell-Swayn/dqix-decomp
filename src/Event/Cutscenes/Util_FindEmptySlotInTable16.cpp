#include <globaldefs.h>
ARM
// Original data: arm9/ov001 @ 0x2165958; symbol: data_ov001_02165958.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 80 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov001.md.
extern "C" void *UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[16];
// Original: arm9/ov001 @ 0x0215A818; symbol: func_ov001_0215a818; size: 0x38.
extern "C" void *Util_FindEmptySlotInTable16(unsigned int *index) {
    for (int i = 0; i < 16; i++) {
        if (UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[i] == 0) {
            *index = i;
            return &UtilFindEmptySlotInTable16_UnknownRoleZeroInitializedStorage[i];
        }
    }
    return 0;
}
