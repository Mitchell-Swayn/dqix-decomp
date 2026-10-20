#include <globaldefs.h>
#include <GameState/GameState.h>
ARM
struct GameState;struct Owner;struct Inventory;
extern "C" {
GameObject* GameState_GetObjectWithFlag100(GameState*,int);
void* GameState_GetIndexList(GameState*);
void GameObject_SetLinkedStatAndMarkChanged(Owner*,int,int);
int Inventory_AddItemQuantityToTypeGroup(Inventory*,unsigned,int,unsigned);
int Menu_GetSelectedInventoryPartyMember(void*);
int Menu_EquipSelectedItemAndRefreshParty(void*,unsigned);
}
struct Indices {unsigned char data[8];};
// Original data: arm9/ov004 @ 0x216fb20; symbol: data_ov004_0216fb20.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 08090001070506ff.
// Observed span: 8 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" Indices ReturnDisallowedSelectedEquipmentToInventory_UnknownRoleInitializedBytes;
// Original data: arm9/ov004 @ 0x216fc1c; symbol: data_ov004_0216fc1c.
// Original initialized data used by the recorded consumers. Semantic role, logical type and object extent remain unresolved.
// Initial values: hex 0700000008000000000000000100000006000000040000000500000009000000ffffffff.
// Observed span: 36 bytes; not a proven logical object extent.
// Full values and references: docs/data-symbols/ov004.md.
extern "C" int ReturnDisallowedSelectedEquipmentToInventory_UnknownRoleInitializedBytes_Variant2[];
struct Item {unsigned word; unsigned low:27,keepFirst:1,keepSecond:1,blocked:1,upper:2;};
struct Entry {Item* item;unsigned text;unsigned kind:4,rest:28;char padding[12];short count;char tail[6];};
struct Mode {unsigned char selected:1,rest:7;};
// Original: arm9/ov004 @ 0x0215DD3C; symbol: func_ov004_0215dd3c; size: 0x144.
// Removes eligible indexed equipment records, returning their quantity to inventory, then refreshes selection.
extern "C" int ReturnDisallowedSelectedEquipmentToInventory(void* self){
 int selected=Menu_GetSelectedInventoryPartyMember(self);
 GameState* state=GameState::GetInstance();
 GameObject* gameObject=GameState_GetObjectWithFlag100(state,selected);
 if(!gameObject)return 0;
 char* object=(char*)gameObject;
 char* inventory=(char*)GameState_GetIndexList(state);
 Indices indices=ReturnDisallowedSelectedEquipmentToInventory_UnknownRoleInitializedBytes;
 for(unsigned char i=0;i<8;i++){
  unsigned index=indices.data[i];
  if(index==255)break;
  Item* item;
  char* fields=*(char**)(object+0x150);
  Entry* entry=(Entry*)(fields+0x194+index*32);
  if(entry && (item=entry->item) && !item->blocked){
   bool keep[2]={item->keepFirst!=0,item->keepSecond!=0};
   if(!keep[((Mode*)(fields+0x49c))->selected]){
    GameObject_SetLinkedStatAndMarkChanged((Owner*)object,ReturnDisallowedSelectedEquipmentToInventory_UnknownRoleInitializedBytes_Variant2[i],-1);
    if(entry)Inventory_AddItemQuantityToTypeGroup((Inventory*)(inventory+0x1d4),entry->count,1,entry->kind);
   }
  }
 }
 return Menu_EquipSelectedItemAndRefreshParty(self,1);
}
