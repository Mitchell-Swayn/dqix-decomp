#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void *SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
extern "C" void *Menu_FindCategoryCounterByKind(void *, int);
// Original: arm9/ov004 @ 0x02153860; symbol: func_ov004_02153860; size: 0x54.
extern "C" short SumSixIndexedEntryByteValues(void) {
    short sum = 0;
    for (short index = 1; index <= 6; ++index) {
        void *entry = Menu_FindCategoryCounterByKind(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage, index);
        if (entry != 0) sum = (short)(sum + *((unsigned char *)entry + 5));
    }
    return sum;
}
