#include <globaldefs.h>
ARM
extern "C" int GetTypeSevenRowMajorIndex(void*, unsigned);
extern "C" int Menu_GetInventorySlotOnCurrentPage(void*, unsigned);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void InvokeEntryHandlerForStateKey(void*, unsigned, unsigned);
extern "C" void Menu_RefreshPurchaseQuantityAndTotal(void*);
// Original: arm9/ov004 @ 0x021599B4; symbol: func_ov004_021599b4; size: 0x78.
extern "C" int Resource_DecrementActiveEntryAndInvokeHandler(void* object) {
    int index = GetTypeSevenRowMajorIndex(object, 0x5b);
    if (index < 0) return 0;
    if (Menu_GetInventorySlotOnCurrentPage(object, (unsigned)index & 0xff) == 0) return 0;
    unsigned char* state = *(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    unsigned char count = state[0x11];
    if (count <= 1) return 0;
    state[0x11] = count - 1;
    InvokeEntryHandlerForStateKey(object, 0x25c, 1);
    Menu_RefreshPurchaseQuantityAndTotal(object);
    return 0;
}
