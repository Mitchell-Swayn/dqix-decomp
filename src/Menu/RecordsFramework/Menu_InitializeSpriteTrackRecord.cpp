#include <globaldefs.h>
ARM
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
extern "C" void MenuRecord_ResetHeader(void*);extern "C" void* Menu_GetDisplayRecordRegistry(void*);extern "C" void* MenuRecordList_LocateByKey(void*,unsigned);extern "C" char* Menu_GetRecordSpriteResource(void*);extern "C" int MenuRecordList_FindFreeSpriteSlotRange(void*,int,int);extern "C" void MenuRecordList_ReserveSpriteSlotRange(void*,int,unsigned,int);
// Original: arm9/ov023 @ 0x021FB2B0; symbol: InitializeTypeElevenResourceAndReserveSlot; size: 0xb4.
extern "C" int Menu_InitializeSpriteTrackRecord(char* self,void* owner,unsigned a,unsigned b,unsigned key,unsigned mode){
MenuRecord_ResetHeader(self);H(self,4)=11;H(self,6)=a;H(self,8)=b;H(self,10)=0;W(self,16)=0;W(self,28)=2;H(self,32)=key;void* tree=Menu_GetDisplayRecordRegistry(owner);void* entry=MenuRecordList_LocateByKey(tree,H(self,32));if(!entry)return 0;int group=B(Menu_GetRecordSpriteResource(entry),80);H(self,34)=mode;H(self,36)=MenuRecordList_FindFreeSpriteSlotRange(tree,group,1);MenuRecordList_ReserveSpriteSlotRange(tree,group,H(self,36),1);H(self,38)=0;H(self,40)=0;H(self,42)=0;return 1;
}
