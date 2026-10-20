#include <globaldefs.h>
ARM
extern "C" char* TextContext_GetSharedInstance();
extern "C" void TextLayout_ResetFormattingWorkspace(void*);
extern "C" void* Menu_GetInventoryRecordSourceByKey(void*,int);
extern "C" char* ZoneState2754_FindPrimaryRecordByKey(void*,int);
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char* MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void* Text_LookupNameTableEntry(void*,int);
extern "C" void TextContext_SetNumericArgument(void*,int,unsigned);
// Original: arm9/ov004 @ 0x0215B120; symbol: Graphics_SetSerializedRecordDisplayValueAndCount; size: 0xb4.
// Finds serialized primary record and displays resolved value with owner amount and optional count.
extern "C" int Menu_PrepareListingPriceMessage(void* self) {
 char* display=TextContext_GetSharedInstance();TextLayout_ResetFormattingWorkspace(display);
 char* record=ZoneState2754_FindPrimaryRecordByKey(Menu_GetInventoryRecordSourceByKey(self,5),*(short*)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]+0x6c));char* owner=MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2];
 if(*(unsigned char*)(owner+0x6e)==1){*(void**)(display+0x18)=Text_LookupNameTableEntry(owner+0x8c,*(short*)(record+0x18));TextContext_SetNumericArgument(display,0,*(unsigned*)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]+0x78));}
 else{*(void**)(display+0x18)=Text_LookupNameTableEntry(owner+0x8c,*(short*)(record+0x18));TextContext_SetNumericArgument(display,0,*(unsigned*)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]+0x78));TextContext_SetNumericArgument(display,1,*(unsigned char*)(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[2]+0x6e));}return 0;
}
