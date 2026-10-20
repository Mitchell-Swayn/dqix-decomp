#include <globaldefs.h>
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void* Menu_FindInventoryValueEntryByKey(void*, unsigned);
// Original: arm9/ov004 @ 0x0215AF80; symbol: func_ov004_0215af80; size: 0x70.
extern "C" int Resource_InvokeType15CallbacksForTwoKeys(void* self) {
    void* entry = Menu_FindInventoryValueEntryByKey(self, 0x25a);
    if (entry != 0) {
        void* context = *(void**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
        void** vtable = *(void***)entry;
        ((void (*)(void*, unsigned))(*(void**)((char*)vtable + 0xe0)))(entry, *(unsigned char*)((char*)context + 0x6e));
    }
    entry = Menu_FindInventoryValueEntryByKey(self, 0x2bd);
    if (entry != 0) {
        void* context = *(void**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
        void** vtable = *(void***)entry;
        ((void (*)(void*, unsigned))(*(void**)((char*)vtable + 0xe0)))(entry, *(unsigned*)((char*)context + 0x78));
    }
    return 0;
}
