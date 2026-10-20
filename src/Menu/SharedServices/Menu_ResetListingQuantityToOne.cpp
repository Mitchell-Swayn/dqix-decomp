#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage;
extern "C" void* Menu_FindInventoryValueEntryByKey(void*, unsigned);
extern "C" void* Menu_FindInventoryTextCanvasByKey(void*, unsigned);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
// Original: arm9/ov004 @ 0x0215C684; symbol: func_ov004_0215c684; size: 0x78.
extern "C" int Menu_ResetListingQuantityToOne(void* self) {
    if (*(unsigned char*)(*(unsigned char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8) + 0x6e) > 1) {
        *(unsigned char*)(*(unsigned char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8) + 0x6e) = 1;
        void* entry = Menu_FindInventoryValueEntryByKey(self, 0x25a);
        if (entry != 0) {
            void (*callback)(void*, unsigned) = *(void (**)(void*, unsigned))(*(char**)entry + 0xe0);
            callback(entry, *(unsigned char*)(*(unsigned char**)((char*)&MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8) + 0x6e));
        }
        void* target = Menu_FindInventoryTextCanvasByKey(self, 0x19);
        if (target != 0) MenuTextCanvas_RefreshConfiguredFrameAndContents(target, self);
    }
    return 0;
}
