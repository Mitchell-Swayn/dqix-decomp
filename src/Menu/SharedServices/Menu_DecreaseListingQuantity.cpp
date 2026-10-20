#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
extern "C" void *Menu_FindInventoryValueEntryByKey(void *self, unsigned key);
extern "C" void *Menu_FindInventoryTextCanvasByKey(void *self, unsigned id);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void *entry, void *state);
// Original: arm9/ov004 @ 0x0215B0A8; symbol: func_ov004_0215b0a8; size: 0x78.
extern "C" int Menu_DecreaseListingQuantity(void *self) {
    char *state = *(char **)(&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    unsigned char selection = (unsigned char)state[0x6e];
    if (selection > 1) {
        state[0x6e] = selection - 1;
        void *entry = Menu_FindInventoryValueEntryByKey(self, 0x25a);
        if (entry) {
            void *object = *(void **)entry;
            void (*callback)(void *, unsigned) = *(void (**)(void *, unsigned))((char *)object + 0xe0);
            (*callback)(entry, (unsigned char)(*(char **)(&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8))[0x6e]);
        }
        void *found = Menu_FindInventoryTextCanvasByKey(self, 0x19);
        if (found) MenuTextCanvas_RefreshConfiguredFrameAndContents(found, self);
    }
    return 0;
}
