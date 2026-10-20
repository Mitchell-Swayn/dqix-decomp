#include <globaldefs.h>
ARM
extern "C" int GetTypeSevenRowMajorIndex(void*, unsigned);
extern "C" int Menu_GetInventorySlotOnCurrentPage(void*, unsigned);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" void* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
extern "C" void InvokeEntryHandlerForStateKey(void*, unsigned, unsigned);
extern "C" void Menu_RefreshPurchaseQuantityAndTotal(void*);
// Original: arm9/ov004 @ 0x0215C494; symbol: GameState_ActivateKeyedTypeSevenEntry; size: 0x78.
// Looks up and validates type-seven key 0x5b, sets the shared state byte, notifies on byte wrap, then updates the owner.
extern "C" int Menu_ResetPurchaseQuantityToOne(void* self) {
    int index = GetTypeSevenRowMajorIndex(self, 0x5b);
    if (index < 0) return 0;
    if (!Menu_GetInventorySlotOnCurrentPage(self, (unsigned char)index)) return 0;
    unsigned char previous = (*(unsigned char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8))[0x11];
    (*(unsigned char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8))[0x11] = 1;
    if ((*(unsigned char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8))[0x11] < previous) InvokeEntryHandlerForStateKey(self, 0x25c, 1);
    Menu_RefreshPurchaseQuantityAndTotal(self);
    return 0;
}
