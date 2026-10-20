#include <globaldefs.h>
ARM
// Original: arm9/ov025:021e6340; Stores the object halfword at +8 to overlay control +0x6f04 and invokes the resource operation with that index.
extern "C" unsigned BattleScene_GetActiveInstance();
// Original data: arm9/main @ 0x2108760; symbol: data_02108760.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 208 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/main.md.
extern "C" unsigned char Main_UnknownRoleZeroInitializedStorage;
extern "C" void ResourceHandle_InvokeOperationWithValidHalfwordIndex(char *, int, int, int);
extern "C" int Resource_StoreObjectIndexAndInvokeOperation(const unsigned char *object) {
    volatile unsigned short *destination = (volatile unsigned short *)((unsigned char *)BattleScene_GetActiveInstance() + 0x6f04);
    unsigned short index = *(const unsigned short *)(object + 8);
    *destination = index;
    ResourceHandle_InvokeOperationWithValidHalfwordIndex((char *)&Main_UnknownRoleZeroInitializedStorage, *(const volatile unsigned short *)(object + 8), 0, index);
    return 1;
}
