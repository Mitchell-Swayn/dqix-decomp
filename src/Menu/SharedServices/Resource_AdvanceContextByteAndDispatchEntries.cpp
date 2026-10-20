#include <globaldefs.h>
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" unsigned char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void* Menu_FindInventoryValueEntryByKey(void*, unsigned);
extern "C" void* Menu_FindInventoryTextCanvasByKey(void*, unsigned);
extern "C" void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*, void*);
// Original: arm9/ov004 @ 0x0215C6FC; symbol: func_ov004_0215c6fc; size: 0x78.
extern "C" int Resource_AdvanceContextByteAndDispatchEntries(void* object) {
    unsigned char* context = *(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8);
    if (context[0x6e] < context[0x6f]) {
        context[0x6e] = context[0x6f];
        void* entry = Menu_FindInventoryValueEntryByKey(object, 0x25a);
        if (entry) {
            ((void (*)(void*, unsigned))(*(void**)((char*)*(void**)entry + 0xe0)))(entry, *(unsigned char*)(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage + 8) + 0x6e));
        }
        entry = Menu_FindInventoryTextCanvasByKey(object, 0x19);
        if (entry) MenuTextCanvas_RefreshConfiguredFrameAndContents(entry, object);
    }
    return 0;
}
