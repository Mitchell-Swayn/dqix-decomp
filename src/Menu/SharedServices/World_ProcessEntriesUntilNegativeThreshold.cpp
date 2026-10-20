#include <globaldefs.h>
ARM
struct ThresholdTable { int values[3]; };
extern "C" void Menu_RebuildAlternateCatalogueFilteredList();
extern "C" void MenuTextCanvas_RedrawByKey(void*, int);
// Original data: arm9/ov004 @ 0x216fae0; symbol: data_ov004_0216fae0.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 3200000033000000ffffffff.
// Observed span: 12 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" ThresholdTable WorldProcessEntriesUntilNegativeThreshold_UnknownRoleInitializedBytes;
// Original: arm9/ov004 @ 0x02155B6C; symbol: func_ov004_02155b6c; size: 0x50.
extern "C" int World_ProcessEntriesUntilNegativeThreshold(void* object) {
    Menu_RebuildAlternateCatalogueFilteredList();
    ThresholdTable local = WorldProcessEntriesUntilNegativeThreshold_UnknownRoleInitializedBytes;
    int index = 0;
    while (local.values[index] >= 0) {
        MenuTextCanvas_RedrawByKey(object, local.values[index]);
        ++index;
    }
    return 0;
}
