#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707c4; symbol: data_ov004_021707c4.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void *MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage;
extern "C" void* Menu_FindAlternateCategoryCounter(void*, int);
// Original: arm9/ov004 @ 0x02155090; symbol: func_ov004_02155090; size: 0x38.
extern "C" int Menu_GetCompletedAlternateCategoryEightCount(void) {
    short value = 0;
    void *record = Menu_FindAlternateCategoryCounter(MenuRebuildAlternateCatalogueFilteredList_UnknownRoleZeroInitializedStorage, 8);
    if (record) value += (unsigned char)((char *)record)[5];
    return value;
}
