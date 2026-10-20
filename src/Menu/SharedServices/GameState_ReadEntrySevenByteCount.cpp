#include <globaldefs.h>
ARM
extern "C" short* Menu_FindCategoryCounterByKind(short*, int);
// Original data: arm9/ov004 @ 0x21707c0; symbol: data_ov004_021707c0.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 4 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" short* SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage;
// Original: arm9/ov004 @ 0x021538F0; symbol: func_ov004_021538f0; size: 0x54.
extern "C" int GameState_ReadEntrySevenByteCount(void) {
    short result = 0;
    short index = 7;
    while (index <= 7) {
        short* record = Menu_FindCategoryCounterByKind(SumSixIndexedEntryByteValues_UnknownRoleZeroInitializedStorage, index);
        if (record) result = (short)(result + ((unsigned char*)record)[5]);
        index = (short)(index + 1);
    }
    return result;
}
