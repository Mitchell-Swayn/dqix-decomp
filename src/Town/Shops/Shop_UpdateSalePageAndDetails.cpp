#include <globaldefs.h>
ARM
#pragma opt_common_subs off
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(short*)((char*)(p)+(o)))
#define U(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define W(p,o) (*(unsigned*)((char*)(p)+(o)))
#define P(p,o) (*(char**)((char*)(p)+(o)))
extern "C" void GameState_ClampSelectedListEntry(void*);extern "C" void Shop_RefreshSellableItemList(void*);extern "C" void Shop_RefreshPartyEquipmentComparisons(void*);
// Original: arm9/ov003 @ 0x0217A14C; symbol: UpdateWrappedPageAndRefreshChangedSelection; size: 0xD4.
extern "C" void Shop_UpdateSalePageAndDetails(char* self){int step=0;unsigned flags=W(self,0xfe4);if(flags&16)step=1;else if(flags&32)step--;H(self,0x1014)+=step;if(H(self,0x1016)<=H(self,0x1014))H(self,0x1014)=0;if(H(self,0x1014)<0)H(self,0x1014)=H(self,0x1016)-1;if(step){GameState_ClampSelectedListEntry(self);Shop_RefreshSellableItemList(self);if(H(self,0x100c)==119)Shop_RefreshPartyEquipmentComparisons(self);}GameState_ClampSelectedListEntry(self);if(H(self,0x1000)!=H(P(self,0xff8),0)){Shop_RefreshSellableItemList(self);if(H(self,0x100c)==119)Shop_RefreshPartyEquipmentComparisons(self);}}
