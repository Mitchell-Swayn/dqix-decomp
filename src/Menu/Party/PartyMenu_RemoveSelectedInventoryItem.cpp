#include <globaldefs.h>
ARM
extern "C" int ZoneState2754_FindPrimaryRecordByKey(...);
extern "C" int GameState_GetIndexList(...);
extern "C" int GameState_GetObjectWithFlag100(...);
extern "C" int GameObject_GetLinkedIndexedState(...);
extern "C" int CharacterState_RemoveCarriedItemAtIndex(...);
extern "C" int Inventory_ConsumeSelectedItem(...);
extern "C" int ValidatePartyIndexAndResourceSlot(...);
extern "C" int _ZN9GameState11GetInstanceEv(...);
extern "C" int Inventory_RemoveItemCountAndCompact(...);
extern "C" void* memset(void*,int,unsigned);extern "C" unsigned strlen(const char*);
#define P(p,o) (*(char**)((char*)(p)+(o)))
#define W(p,o) (*(int*)((char*)(p)+(o)))
#define B(p,o) (*(unsigned char*)((char*)(p)+(o)))
#define H(p,o) (*(unsigned short*)((char*)(p)+(o)))
#define S(p,o) (*(short*)((char*)(p)+(o)))
// Original: arm9/ov002 @ 0x0215A7B4; symbol: RemovePartyOrResourceSelectionAndMarkMenuDirty; size: 0xc4.
extern "C" void PartyMenu_RemoveSelectedInventoryItem(char* self,int index,int key,int slot,unsigned char resource){
void* state=(void*)_ZN9GameState11GetInstanceEv();if(index==4){if(resource){void* entry=(void*)ZoneState2754_FindPrimaryRecordByKey(self+0x7ec,key);if(entry)Inventory_ConsumeSelectedItem(entry);}else Inventory_RemoveItemCountAndCompact(GameState_GetIndexList(state),key,1);B(self,0x2478)=1;return;}if(resource)ValidatePartyIndexAndResourceSlot(index,slot,self+0x7ec,0);else{void* object=(void*)GameState_GetObjectWithFlag100(state,index);if(!object)return;CharacterState_RemoveCarriedItemAtIndex(GameObject_GetLinkedIndexedState(object),(signed char)slot);}B(self,0x2478)=1;
}
