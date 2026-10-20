#include <globaldefs.h>
ARM
struct State;
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void Menu_ResetItemListingSelection(void *record);
extern "C" void Menu_QueueScriptEntry(State *self, unsigned value);
// Original: arm9/ov004 @ 0x0215B330; symbol: func_ov004_0215b330; size: 0x30.
extern "C" int Menu_CancelItemListingSelection(State *self) {
    Menu_ResetItemListingSelection(*(void **)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8));
    Menu_QueueScriptEntry(self, 0x39e);
    return 0;
}
