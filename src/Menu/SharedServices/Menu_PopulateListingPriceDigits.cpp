#include <globaldefs.h>
ARM
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define S(p,o) (*(signed char*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
// Original data: arm9/ov004 @ 0x21707d8; symbol: data_ov004_021707d8.
// Zero-initialized global storage. Runtime values are written by its consumers; semantic role and logical object size remain unresolved.
// Initial values: zero-filled at load; mutable at runtime.
// Observed span: 16 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" char MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage[];
extern "C" void* Menu_GetInventoryRecordSourceByKey(void*,int);
extern "C" void* ZoneState2754_FindPrimaryRecordByKey(void*,int);
extern "C" void* Menu_FindInventorySpriteByKey(void*,int);
extern "C" void Menu_SetSpriteCellIndex(void*,unsigned short);
// Original: arm9/ov004 @ 0x0215AD34; symbol: PopulateSevenDecimalDigitDescriptorValues; size: 0xc4.
extern "C" int Menu_PopulateListingPriceDigits(void* self) {
 if(!ZoneState2754_FindPrimaryRecordByKey(Menu_GetInventoryRecordSourceByKey(self,5),H(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0x6c)))return 0;
 int value=W(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0x78);for(int i=0;i<7;i++){B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)+i,0x3f)=value%10;value/=10;void* record=Menu_FindInventorySpriteByKey(self,i+45);if(record)Menu_SetSpriteCellIndex(record,(unsigned short)(S(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8)+i,0x3f)+26));}B(P(MenuRefreshSixOfferRows_UnknownRoleZeroInitializedStorage,8),0x3e)=0;return 0;
}
