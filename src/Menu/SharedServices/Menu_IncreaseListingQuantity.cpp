#include <globaldefs.h>
ARM
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" {extern char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[]; void* Menu_FindInventoryValueEntryByKey(void*,unsigned);void* Menu_FindInventoryTextCanvasByKey(void*,unsigned);void MenuTextCanvas_RefreshConfiguredFrameAndContents(void*,void*);}
// Original: arm9/ov004 @ 0x0215B02C; symbol: IncrementBoundedSelectionAndRefresh; size: 0x7c.
// Increments selection byte6E below byte6F, updates entry25A and refreshes type-six entry19.
extern "C" int Menu_IncreaseListingQuantity(void* self) {
 unsigned char* p=*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8);
 if(p[0x6e]<p[0x6f]) {++p[0x6e];void* entry=Menu_FindInventoryValueEntryByKey(self,0x25a);if(entry) ((void(*)(void*,unsigned))(*(void***)entry)[0xe0/4])(entry,(*(unsigned char**)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage+8))[0x6e]);void* item=Menu_FindInventoryTextCanvasByKey(self,0x19);if(item)MenuTextCanvas_RefreshConfiguredFrameAndContents(item,self);}
 return 0;
}
