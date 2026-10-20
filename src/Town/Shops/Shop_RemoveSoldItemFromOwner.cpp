#include <globaldefs.h>
ARM
extern "C" int FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(...);
extern "C" int GameState_GetIndexList(...);
extern "C" int GameObject_GetLinkedIndexedState(...);
extern "C" int CharacterState_RemoveCarriedItemAtIndex(...);
extern "C" int Inventory_SubtractItemQuantityFromTypeGroup(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int _ZN9GameState21GetPartyMemberByIndexEi(...);
extern "C" int Inventory_RemoveItemCountAndCompact(...);
extern "C" void* memcpy(void*,const void*,unsigned);extern "C" void* memset(void*,int,unsigned);extern "C" char* strcpy(char*,const char*);extern "C" int sprintf(char*,const char*,...);

#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
#define C(x) ((char*)(x))
struct Nibble{unsigned low:4;unsigned rest:28;};
// Original: arm9/ov003 @ 0x02175DF4; symbol: RemoveSelectedKeyedCountOrPartyHalfwordEntry.
extern "C" int Shop_RemoveSoldItemFromOwner(char*self){
int game=_ZN9GameState11GetInstanceEv();char*list=C(GameState_GetIndexList(game));if(S(self+4096,12)==119)return Inventory_SubtractItemQuantityFromTypeGroup(list+468,S(self+4096,58),*(signed char*)(self+4156),((Nibble*)(P(self,8)+8))->low);int key;switch(W(self+4096,48)){case 1:key=17;break;case 2:key=18;break;case 3:key=19;break;case 4:key=20;break;}short index=S(self+4096,16)-FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(P(self,2204),key);if(W(self+4096,48)>index){char*member=C(_ZN9GameState21GetPartyMemberByIndexEi(game,W(self+index*4+4096,28)));if(!member)return 0;short slot=S(self+4096,14)-FindGroupRecordWithNonzeroFieldsAndFlagTwoClear(P(self,2204),21);CharacterState_RemoveCarriedItemAtIndex(GameObject_GetLinkedIndexedState(member),(signed char)slot);return 1;}Inventory_RemoveItemCountAndCompact(list,S(self+4096,58),*(signed char*)(self+4156));return 1;
}
